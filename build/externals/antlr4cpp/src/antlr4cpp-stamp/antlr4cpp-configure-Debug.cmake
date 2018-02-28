

set(command "/usr/local/Cellar/cmake/3.10.2/bin/cmake;-DCMAKE_BUILD_TYPE=Release;-DANTLR4CPP_JAR_LOCATION=/Users/tbourvon/Drive/Projects/Programming/HexaC/thirdparty/antlr-4.7.1-complete.jar;-DBUILD_SHARED_LIBS=ON;-BUILD_TESTS=OFF;-DCMAKE_INSTALL_PREFIX:PATH=/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp;-DCMAKE_SOURCE_DIR:PATH=/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp/runtime/Cpp;/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp/runtime/Cpp")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-out.log"
  ERROR_FILE "/Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "antlr4cpp configure command succeeded.  See also /Users/tbourvon/Drive/Projects/Programming/HexaC/build/externals/antlr4cpp/src/antlr4cpp-stamp/antlr4cpp-configure-*.log")
  message(STATUS "${msg}")
endif()
