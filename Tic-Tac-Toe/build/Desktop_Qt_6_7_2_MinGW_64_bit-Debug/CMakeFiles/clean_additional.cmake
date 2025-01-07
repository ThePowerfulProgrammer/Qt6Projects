# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Tic-Tac-Toe_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Tic-Tac-Toe_autogen.dir\\ParseCache.txt"
  "Tic-Tac-Toe_autogen"
  )
endif()
