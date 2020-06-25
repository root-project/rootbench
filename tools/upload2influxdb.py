#!/usr/bin/python

import argparse
import csv
from influxdb import InfluxDBClient
import os
import logging


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
    return parser.parse_args()


def create_influxdb_client(database_url, database_name, username, password, port=8080):
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
    return None


def extract_from_pytest(lines):
    return None


def upload(client, data):
    pass


def main(basedir, influx_client, dry_run):
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
            logger.debug('Extracted data from csv: %s', data)

            # Upload data to the Influx database
            if not dry_run:
                upload(client, data)


if __name__ == '__main__':
    args = parse_arguments()
    setup_logging(args.log_level)
    client = create_influxdb_client(args.database_url, args.database_name, args.username, args.password)
    main(args.basedir, client, args.dry_run)
