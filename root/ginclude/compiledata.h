/* This file is automatically generated */
#define BUILD_ARCH "macosxarm64"
#define BUILD_NODE "Darwin abhigyans-air.guest.uc.edu 22.6.0 Darwin Kernel Version 22.6.0: Wed Jul 5 22:17:35 PDT 2023; root:xnu-8796.141.3~6/RELEASE_ARM64_T8112 arm64"
#define CXX "c++"
#define COMPILER "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++"
#define COMPILERVERS "clang1500"
#define COMPILERVERSSTR "Apple clang version 15.0.0 (clang-1500.1.0.2.5)"
#define MAKESHAREDLIB  "cd $BuildDir ; c++ -fPIC -c $Opt -std=c++17 -Wc++11-narrowing -Wsign-compare -Wsometimes-uninitialized -Wconditional-uninitialized -Wheader-guard -Warray-bounds -Wcomment -Wtautological-compare -Wstrncat-size -Wloop-analysis -Wbool-conversion -m64 -pipe -W -Woverloaded-virtual -fsigned-char -fno-common -Qunused-arguments -pthread -stdlib=libc++ $IncludePath $SourceFiles ; c++ $Opt $ObjectFiles -dynamiclib -Wl,-headerpad_max_install_names -m64 -Wl,-dead_strip_dylibs -Wl,-rpath,$ROOTSYS/lib  -mmacosx-version-min=13.5 $LinkedLibs -o $SharedLib"
#define MAKEEXE "cd $BuildDir ; c++ -c $Opt -std=c++17 -Wc++11-narrowing -Wsign-compare -Wsometimes-uninitialized -Wconditional-uninitialized -Wheader-guard -Warray-bounds -Wcomment -Wtautological-compare -Wstrncat-size -Wloop-analysis -Wbool-conversion -m64 -pipe -W -Woverloaded-virtual -fsigned-char -fno-common -Qunused-arguments -pthread -stdlib=libc++ $IncludePath $SourceFiles; c++ $Opt $ObjectFiles  -mmacosx-version-min=13.5 -o $ExeName $LinkedLibs"
#define CXXOPT "-O3 -DNDEBUG"
#define CXXDEBUG "-g"
#define ROOTBUILD "debug"
#define LINKEDLIBS "-L$ROOTSYS/lib -lCore -lRint "
#define INCLUDEPATH "-I$ROOTSYS/include"
#define OBJEXT "o"
#define SOEXT "so"
