# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\crude3DRendering_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\crude3DRendering_autogen.dir\\ParseCache.txt"
  "crude3DRendering_autogen"
  )
endif()
