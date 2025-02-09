# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\drawTheMap_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\drawTheMap_autogen.dir\\ParseCache.txt"
  "drawTheMap_autogen"
  )
endif()
