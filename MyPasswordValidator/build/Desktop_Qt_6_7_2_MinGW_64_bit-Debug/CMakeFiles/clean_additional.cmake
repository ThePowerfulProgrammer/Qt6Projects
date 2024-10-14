# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyPasswordValidator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyPasswordValidator_autogen.dir\\ParseCache.txt"
  "MyPasswordValidator_autogen"
  )
endif()
