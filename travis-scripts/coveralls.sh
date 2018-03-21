#!/bin/bash
source /travis/.bashrc
echo "LCOV combining all parts"
$LCOV -a $HOME_FOLDER/build/coverage.init_part1 -a $HOME_FOLDER/build/coverage.init_part2 -a $HOME_FOLDER/build/coverage.info_part1 -a $HOME_FOLDER/build/coverage.info_part2 -o $HOME_FOLDER/build/coverage.total &> log
$LCOV -r $HOME_FOLDER/build/coverage.total \*/usr* \*/*-prefix/* \*/G__*.cxx \*/install/* \*/qtgsi/* \*/Pythia8/* \*/TDav* \*/CMake*.cpp  \*/*.gen  \*/*.inc  \*/*.def  \*/VecCore/* \*/Roo1* \*/Roo2*  \*/interpreter/* -o $HOME_FOLDER/build/coverage.total &> log
$LCOV -r $HOME_FOLDER/build/coverage.total \*/build/workspace/lcg_ext_rootcov/* -o $HOME_FOLDER/build/coverage.total &> log
$LCOV -r $HOME_FOLDER/build/coverage.total \*/mnt/vdb/lsf/workspace/lcg_ext_rootcov/* -o $HOME_FOLDER/build/coverage.total &> log
$LCOV -r $HOME_FOLDER/build/coverage.total \*/rootbench/root/* -o $HOME_FOLDER/build/coverage.total &> log
$LCOV -r $HOME_FOLDER/build/coverage.total \*/graf3d/eve/src/TEveTrans.cxx -o $HOME_FOLDER/build/coverage.total &> log
$LCOV -r $HOME_FOLDER/build/coverage.total \*/interpreter/cling/test/Pragmas/P* -o $HOME_FOLDER/build/coverage.total &> log
#perl -p -i -e "s|$ROOTSYS||g" coverage.total
#perl -p -i -e "s|$HOME_folder/rootsource||g" coverage.total
cd ../rootsource
LINES=0 $HOME_FOLDER/travis-fix/travis_wait_log 1 coveralls-lcov -v $HOME_FOLDER/build/coverage.total
