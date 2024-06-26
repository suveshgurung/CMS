# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMS_autogen"
  "CMakeFiles/CMS_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CMS_autogen.dir/ParseCache.txt"
  )
endif()
