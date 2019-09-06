#!/bin/bash
source /travis/.bashrc
touch $HOME/build/coverage.init_part2
echo "LCOV init part 2 (due complex setup of CI slaves for ROOT builds)"
export LCOV_PATH_ROOT="\"geninfo_adjust_src_path=/mnt/build/workspace/lcg_ext_rootcov/BUILDTYPE/Release/COMPILER/native/LABEL/ubuntu16/build/projects/ROOT-HEAD/src/ROOT/HEAD/=> `echo $HOME/rootsource/`\""
$HOME/travis-fix/travis_wait_log 5 $LCOV --gcov-tool gcov -c -i -d $HOME/coveralls/ --no-markers --quiet --base-directory `pwd` \
--rc $LCOV_PATH_ROOT \
--output-file $HOME/build/coverage.init_part2