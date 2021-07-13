#----------------------------------------------------------------------------
# # Options for rootbench repository
#
# # TBD: to introduce special function for options (similar to root.git)
#----------------------------------------------------------------------------
option(coverage OFF)

option(rootbench-datafiles OFF "Download files from root.cern.ch")

option(experiment-datafiles OFF "Use for benchmarking CMS and ATLAS files (> 1.5 GB)")
if(experiment-datafiles)
    # We need to enable download of datafiles from oot.cern.ch
    set(rootbench-datafiles ON CACHE BOOL "Download files from root.cern.ch" FORCE)
endif()