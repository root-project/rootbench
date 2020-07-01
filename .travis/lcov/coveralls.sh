#!/bin/bash
source $HOME/.bashrc
echo "LCOV combining all parts"
$LCOV -a $HOME/build/coverage.init_part1 -a $HOME/build/coverage.init_part2 -a $HOME/build/coverage.info_part1 -a $HOME/build/coverage.info_part2 -o $HOME/build/coverage.total &> log
$LCOV -r $HOME/build/coverage.total \*/usr* \*/*-prefix/* \*/G__*.cxx \*/install/* \*/qtgsi/* \*/Pythia8/* \*/TDav* \*/CMake*.cpp  \*/*.gen  \*/*.inc  \*/*.def  \*/VecCore/* \*/Roo1* \*/Roo2*  \*/interpreter/* -o $HOME/build/coverage.total &> log
$LCOV -r $HOME/build/coverage.total \*/build/workspace/lcg_ext_rootcov/* -o $HOME/build/coverage.total &> log
$LCOV -r $HOME/build/coverage.total \*/mnt/vdb/lsf/workspace/lcg_ext_rootcov/* -o $HOME/build/coverage.total &> log
$LCOV -r $HOME/build/coverage.total \*/rootbench/root/* -o $HOME/build/coverage.total &> log
$LCOV -r $HOME/build/coverage.total \*/graf3d/eve/src/TEveTrans.cxx -o $HOME/build/coverage.total &> log
$LCOV -r $HOME/build/coverage.total \*/interpreter/cling/test/Pragmas/P* -o $HOME/build/coverage.total &> log
#perl -p -i -e "s|$ROOTSYS||g" coverage.total
#perl -p -i -e "s|$HOME/rootsource||g" coverage.total
cd ../rootsource
LINES=0 $HOME/travis-fix/travis_wait_log 1 coveralls-lcov -v $HOME/build/coverage.total
