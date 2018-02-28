

set(command "${make}")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-build-out.log"
  ERROR_FILE "/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-build-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-build-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "antlr4cpp build command succeeded.  See also /Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-build-*.log")
  message(STATUS "${msg}")
endif()
