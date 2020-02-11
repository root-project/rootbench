# - Configure and install ROOTBENCH data files
#
#

set(rootbenchsite "http://root.cern.ch/files/rootbench")
set(compression_algorithms "lzma;zlib;none;zstd;lz4")
set(timeout 3600)

function(download_file url filename) # hash_type hash
  if(NOT EXISTS ${filename})
    message(STATUS "INFO: downloading ${url}")
    file(DOWNLOAD ${url} ${filename}
        #TIMEOUT ${timeout}  # seconds
        #EXPECTED_HASH ${hash_type}=${hash}
        #TLS_VERIFY ON
      )
  endif()
endfunction(download_file)

foreach(n ${compression_algorithms})
  set(file_to_download "${rootbenchsite}/h1dst~${n}.root")
  set(file_to_save "${PROJECT_BINARY_DIR}/rootbench_datafiles/h1ds-${n}.root")
  download_file(${file_to_download} ${file_to_save})
endforeach()


