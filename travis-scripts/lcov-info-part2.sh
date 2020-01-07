#!/bin/bash
source $HOME/.bashrc
echo "LCOV info part 2 (due complex setup of CI slaves for ROOT builds)"
export LCOV_PATH_ROOT="\"geninfo_adjust_src_path=/build/workspace/lcg_ext_rootcov/BUILDTYPE/Release/COMPILER/native/LABEL/ubuntu16/build/projects/ROOT-HEAD/src/ROOT/HEAD/=> `echo $HOME/rootsource/`\""
touch $HOME/build/coverage.info_part2
$HOME/travis-fix/travis_wait_log 5 $LCOV --gcov-tool gcov -c -d $HOME/coveralls/ --no-markers --quiet  --base-directory `pwd` --ignore-errors graph \
--rc $LCOV_PATH_ROOT \
--output-file $HOME/build/coverage.info_part2 \