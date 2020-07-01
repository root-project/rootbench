#!/bin/bash

cd $HOME
  #d=$(date +%a)
  #for i in `seq 1 7`; do
  #  ROOT_LOCATION=/cvmfs/sft-nightlies.cern.ch/lcg/nightlies/rootcov/$d/ROOT
  #  echo $ROOT_LOCATION
  #  ROOT_THISROOT=$ROOT_LOCATION/HEAD-*/x86_64-ubuntu1604-gcc54-opt/bin/thisroot.sh
  #  if [ -f $ROOT_THISROOT ]; then
  #     break;
  #  fi
  #  d=$(date +%a -d "$d - 1 day")
  #done;
ROOT_THISROOT=$HOME/root/bin/thisroot.sh
echo "Initializing ROOT in $ROOT_THISROOT"
source $ROOT_THISROOT
echo export ROOTSYS=`echo $ROOTSYS` >> $HOME/.bashrc
echo source $ROOTSYS/bin/thisroot.sh >> $HOME/.bashrc
cat $HOME/.bashrc
mkdir -p $HOME/build
cd $HOME/build
export GCOV_PREFIX=`pwd`
export GCOV_PREFIX_STRIP=0
cmake -DCMAKE_C_COMPILER=${CC} -DCMAKE_CXX_COMPILER=${CXX} \
        -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_CXX_FLAGS="${EXTRA_FLAGS}" \
        ${EXTRA_OPTS} $TRAVIS_BUILD_DIR
cmake --build .
