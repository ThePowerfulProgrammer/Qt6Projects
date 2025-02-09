# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TheWeirdNatureOfVirtualityinCpp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TheWeirdNatureOfVirtualityinCpp_autogen.dir\\ParseCache.txt"
  "TheWeirdNatureOfVirtualityinCpp_autogen"
  )
endif()
