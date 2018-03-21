# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

# compiler must be 11 or 14
SET (CMAKE_CXX_STANDARD 14)

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr-4.7.1-complete.jar)
# add external build for antlrcpp
include( ExternalAntlr4Cpp )
# add antrl4cpp artifacts to project environment
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(demo HexaC
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/HexaCLexer.g4
  ${CMAKE_CURRENT_SOURCE_DIR}/grammar/HexaCParser.g4)
# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_HexaC})

# add generated grammar to demo binary target

file(GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
)

add_executable(HexaC ${SOURCES} ${antlr4cpp_src_files_HexaC})
add_dependencies(HexaC antlr4cpp antlr4cpp_generation_HexaC)
target_link_libraries(HexaC ${ANTLR4CPP_LIBS}/libantlr4-runtime.a)
