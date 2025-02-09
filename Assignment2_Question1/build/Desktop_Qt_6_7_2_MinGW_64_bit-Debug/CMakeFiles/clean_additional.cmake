# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Assignment2_Question1_autogen"
  "CMakeFiles\\Assignment2_Question1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Assignment2_Question1_autogen.dir\\ParseCache.txt"
  )
endif()
