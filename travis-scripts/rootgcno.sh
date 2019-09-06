#!/bin/bash
echo "Downloading Latest ROOT .gcno binaries."
cd $HOME
mkdir $HOME/rootgcno
d=$(date +%a)
for i in `seq 1 7`; do
    ROOTGCNO_TAR=http://lcgpackages.web.cern.ch/lcgpackages/tarFiles/nightlies/rootcov/$d/rootgcno.tgz
    if curl -s -f --head $ROOTGCNO_TAR ; then
      break;
    fi
    d=$(date +%a -d "$d - 1 day")
done;
echo "Downloading and untaring $ROOTGCNO_TAR" && echo -en "travis_fold:start:untar.ROOTGCNO"
wget $ROOTGCNO_TAR
tar zxvf rootgcno.tgz -C $HOME/rootgcno > untar-details.log
mkdir $HOME/lcov && cd $HOME/lcov
wget https://github.com/linux-test-project/lcov/archive/v1.12.zip
unzip v1.12.zip
LCOV="`pwd`/lcov-1.12/bin/lcov"
echo export LCOV=`echo $LCOV` >> /travis/.bashrc
mkdir -p $HOME/coveralls
cp -av $HOME/rootgcno/rootgcno/* $HOME/coveralls/ &> copy_output.log
echo "Cloning ROOT sources"
git clone https://github.com/root-project/root.git $HOME/rootsource
mkdir $HOME/travis-fix
git clone https://github.com/slodki/travis-wait-log.git $HOME/travis-fix