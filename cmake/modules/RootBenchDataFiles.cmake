# - Configure and install ROOTBENCH data files
#
#
set(rootbenchsite "http://root.cern.ch/files/rootbench")
set(timeout 3600)

function(download_file url filename) # hash_type hash
  if(NOT EXISTS ${filename})
    message(STATUS "INFO: downloading ${url}")
    file(DOWNLOAD ${url} ${filename}
        # Currently there are no timeout, hash and TLS checks (to be added later)
        #TIMEOUT ${timeout}  # seconds
        #EXPECTED_HASH ${hash_type}=${hash}
        #TLS_VERIFY ON
      )
  else()
    message(STATUS "INFO: " ${file} " was already downloaded from ${url}")
  endif()
endfunction(download_file)

function(get_file filelist)
    set(file_to_download "${rootbenchsite}/${file}")
    set(file_to_save "${PROJECT_BINARY_DIR}/rootbench-datafiles/${file}")
    download_file(${file_to_download} ${file_to_save})
endfunction(get_file)

