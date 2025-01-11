# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\workingWithDb_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\workingWithDb_autogen.dir\\ParseCache.txt"
  "workingWithDb_autogen"
  )
endif()
