

set(command "/usr/local/Cellar/cmake/3.10.2/bin/cmake;-P;/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/tmp/antlr4cpp-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-download-out.log"
  ERROR_FILE "/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "antlr4cpp download command succeeded.  See also /Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-download-*.log")
  message(STATUS "${msg}")
endif()
