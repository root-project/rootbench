#!/bin/bash
source $HOME/.bashrc
find $HOME/build -name "*.gcda" -exec cp "{}" $HOME/coveralls/ \;
touch $HOME/build/coverage.info_part1
echo "LCOV info part 1 (due complex setup of CI slaves for ROOT builds)"
export LCOV_PATH_ROOTSYS="\"geninfo_adjust_src_path=/build/workspace/lcg_ext_rootcov/BUILDTYPE/Release/COMPILER/native/LABEL/ubuntu16/build/projects/ROOT-HEAD/src/src/ROOT/HEAD/=> `echo $ROOTSYS/`\""
$HOME/travis-fix/travis_wait_log 5 $LCOV --gcov-tool gcov -c -d $HOME/coveralls/ --no-markers --quiet  --base-directory `pwd` --ignore-errors graph \
--rc $LCOV_PATH_ROOTSYS \
--output-file $HOME/build/coverage.info_part1