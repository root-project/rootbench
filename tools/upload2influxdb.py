#!/usr/bin/python

import argparse
import csv
from influxdb import InfluxDBClient
import os
import logging
from datetime import datetime
import json


logger = logging.getLogger('')


def setup_logging(level):
    if level.lower() == 'debug':
        logger.setLevel(logging.DEBUG)
    elif level.lower() == 'info':
        logger.setLevel(logging.INFO)
    else:
        raise Exception('Unknown debug level {}'.format(level))

    formatter = logging.Formatter('%(levelname)s - %(message)s')
    handler = logging.StreamHandler()
    handler.setFormatter(formatter)
    logger.addHandler(handler)


def parse_arguments():
    parser = argparse.ArgumentParser(description='Upload benchmark results from csv files to an Influx database')
    parser.add_argument('--basedir', type=str, required=True,
            help='Base directory to be searched for csv files')
    parser.add_argument('--database-url', type=str, required=True,
            help='URL of the database')
    parser.add_argument('--port', type=int, required=True,
            help='Port for the connection to the database')
    parser.add_argument('--database-name', type=str, required=True,
            help='Name of the database')
    parser.add_argument('--username', type=str, required=True,
            help='Database username')
    parser.add_argument('--password', type=str, required=True,
            help='Database password')
    parser.add_argument('--log-level', type=str, default='info',
            help='Log level [debug, info]')
    parser.add_argument('--dry-run', action='store_true', default=False,
            help='Running without uploading to the Influx database')
    parser.add_argument('--buildtype', type=str, required=True,
            help='Additional data: buildtype')
    parser.add_argument('--buildopts', type=str, required=True,
            help='Additional data: buildopts')
    parser.add_argument('--nodelabel', type=str, required=True,
            help='Additional data: nodelabel')
    parser.add_argument('--compiler', type=str, required=True,
            help='Additional data: compiler')
    return parser.parse_args()


def create_influxdb_client(database_url, database_name, username, password, port):
    client = InfluxDBClient(
            host=database_url,
            port=port,
            username=username,
            password=password,
            database=database_name,
            ssl=True)
    # TODO: How can we test that the client is valid?
    return client


def extract_from_gbenchmark(lines):
    idx = None
    for i, line in enumerate(lines):
        if line.startswith('name,'):
            idx = i
            break

    if idx == None:
        logger.error('gbenchmark csv does not have correct layout')
        raise Exception

    # Drop the first lines, being crap
    lines = lines[idx:]

    # Read data
    reader = csv.reader(lines)
    header = next(reader)
    logger.debug('Extract fields from gbenchmark: %s', header)
    # TODO: Make this check more robust
    if not header[0] == 'name':
        logger.error('gbenchmark header does not have correct layout')
        raise Exception

    data = []
    for row in reader:
        d = {h: row[i] for i, h in enumerate(header)}
        for k, v in d.items():
            try:
                d[k] = float(v)
            except ValueError:
                # We consider that if error was empty then bool value is False
                if k == 'error_occurred':
                    d[k] = bool(False)
                # for others we consider that expected value for empty string shoudl be float
                elif d[k] == '':
                    d[k] = float(0)
                else:
                    d[k] = v
        print(d)
        data.append(d)
    logger.debug('Extracted %u measurements', len(data))

    return data


def extract_from_pytest(lines):
    reader = csv.reader(lines)
    header = next(reader)
    logger.debug('Extract fields from pytest: %s', header)
    # TODO: Make this check more robust
    if not header[0] == 'id':
        logger.error('pytest header does not have correct layout')
        raise Exception

    data = []
    for row in reader:
        d = {h: row[i] for i, h in enumerate(header)}
        d.update({'name': d['id']})
        data.append(d)
    logger.debug('Extracted %u measurements', len(data))

    return data


def upload(client, data, dry_run, additional_data):
    time = datetime.utcnow().strftime('%Y-%m-%dT%H:%M:%SZ')
    influx_metric = []
    for d in data:
        d.update(additional_data)
        influx_metric.append(
                {
                    "measurement": 'gbenchmark',
                    "tags": { 'buildopts', 'buildtype', 'compiler', 'name', 'nodelabel', 'rootbenchmark'},
                    "time": time,
                    "fields": d,
                    }
            )
    logger.debug('Influx metric: %s', json.dumps(influx_metric, indent=4, sort_keys=True))
    if not dry_run:
        client.write_points(influx_metric)
    else:
        logger.warning('Running in dry mode, nothing has been uploaded.')


def main(basedir, influx_client, dry_run, additional_data):
    for root, dirs, files in os.walk(basedir, topdown=True):
        for filename in files:
            # Find csv files
            if not filename.endswith('.csv'):
                continue
            path = os.path.join(root, filename)
            logger.debug('Detected csv file %s', path)

            # Figure out which benchmark type produced the file
            benchmark_type = None
            if filename.startswith('rootbench-gbenchmark'):
                benchmark_type = 'gbenchmark'
            elif filename.startswith('rootbench-pytest'):
                benchmark_type = 'pytest'
            else:
                logger.error('Failed to detect benchmark type of the csv file')
                raise Exception
            logger.debug('Benchmark type: %s', benchmark_type)

            # Read out the columns to be uploaded to the Influx database
            lines = open(path, 'r').readlines()
            if benchmark_type == 'gbenchmark':
                data = extract_from_gbenchmark(lines)
            elif benchmark_type == 'pytest':
                data = extract_from_pytest(lines)
            else:
                raise Exception('Something went wrong with detecting the benchmark type')

            # Upload data to the Influx database
            upload(client, data, dry_run, additional_data)


if __name__ == '__main__':
    args = parse_arguments()
    setup_logging(args.log_level)
    client = create_influxdb_client(args.database_url, args.database_name, args.username, args.password, args.port)
    additional_data = {
            'buildtype': args.buildtype,
            'buildopts': args.buildopts,
            'nodelabel': args.nodelabel,
            'compiler': args.compiler,
            }
    main(args.basedir, client, args.dry_run, additional_data)
