# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExchangeRateApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExchangeRateApp_autogen.dir\\ParseCache.txt"
  "ExchangeRateApp_autogen"
  )
endif()
