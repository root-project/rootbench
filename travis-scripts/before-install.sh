#!/bin/bash
# Install coveralls
gem install coveralls-lcov -v 1.5.1
gem install lcoveralls
wget https://ecsft.cern.ch/dist/cvmfs/cvmfs-release/cvmfs-release-latest_all.deb
dpkg -i cvmfs-release-latest_all.deb
apt-get -y update
apt-get install -y cvmfs cvmfs-config-default
rm -f cvmfs-release-latest_all.deb
mkdir -p /etc/cvmfs/
echo "CVMFS_REPOSITORIES=sft.cern.ch, sft-nightlies.cern.ch, projects.cern.ch" > default.local
echo "CVMFS_HTTP_PROXY=DIRECT" >> default.local
mv default.local /etc/cvmfs/
/etc/init.d/autofs stop
cvmfs_config setup
source /cvmfs/sft.cern.ch/lcg/views/LCG_rootext20171122/x86_64-ubuntu1604-gcc54-opt/setup.sh
env