# Event benchmark

#---Create the dictionary
ROOT_GENERATE_DICTIONARY(EventDict Event.h MODULE Event LINKDEF EventLinkDef.h)

#---Create a shared library with geneated dictionary
add_library(Event SHARED Event.cxx EventDict.cxx)
add_dependencies(Event EventDict)
target_link_libraries(Event ROOT::Hist ROOT::Tree)

#---Create  a main program using the library
add_executable(Main MainEvent.cxx)
target_link_libraries(Main Event)
