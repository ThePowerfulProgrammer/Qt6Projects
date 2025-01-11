# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SimpleGuiInteractionWithDB_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SimpleGuiInteractionWithDB_autogen.dir\\ParseCache.txt"
  "SimpleGuiInteractionWithDB_autogen"
  )
endif()
