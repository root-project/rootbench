#!/bin/sh
rm -f CMakeCache.txt
/opt/homebrew/Cellar/cmake/3.28.2/bin/cmake  -DCMAKE_BUILD_TYPE="RelWithDebInfo" -DCMAKE_INSTALL_PREFIX="/Users/abhiacherjee/Documents/install_root" -Dbuiltin_glew="ON" -Dbuiltin_zlib="OFF" -Dtesting="ON" /Users/abhiacherjee/Documents/root_src 
