RB_GENERATE_DICTIONARY(libh1event ${CMAKE_CURRENT_SOURCE_DIR}/include/h1event.h
                        LINKDEF h1linkdef.h)

add_custom_command(TARGET libh1eventlibgen POST_BUILD
                            COMMAND ${CMAKE_COMMAND} -E copy
                                ${CMAKE_CURRENT_BINARY_DIR}/libh1event.so
                                ${CMAKE_BINARY_DIR}/libh1event.so)
                    
RB_ADD_TOOL(gen_h1 ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_h1.cxx
    LIBRARIES Core Hist Imt RIO Tree TreePlayer 
            ROOTDataFrame ROOTVecOps ROOTNTuple 
            libh1eventlibgen
)

