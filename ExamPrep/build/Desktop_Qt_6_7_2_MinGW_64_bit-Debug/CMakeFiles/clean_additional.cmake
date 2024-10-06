# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExamPrep_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExamPrep_autogen.dir\\ParseCache.txt"
  "ExamPrep_autogen"
  )
endif()
