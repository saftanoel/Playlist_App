# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Lab11_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Lab11_autogen.dir\\ParseCache.txt"
  "Lab11_autogen"
  )
endif()
