cmake_minimum_required(VERSION 3.11.0)

project(chromium_dep_fetcher) 
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
OPTION(GENERATE_DEPSPARSER "Generate dynamic grammar at compile time. Require java 1.7+" ON)
find_package(Qt5Core REQUIRED)

set(PACKAGE_LANGNAME "Depsgrammar")
SET(grammarfname ${PACKAGE_LANGNAME}) 
set(ROOT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(ANTLR_JAR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/antlr4.jar)
set(GRAMMAR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/libs/depsparser/${grammarfname}.g4  )

if(GENERATE_DEPSPARSER)
  find_package(Java COMPONENTS Runtime REQUIRED)
endif(GENERATE_DEPSPARSER)
 
set(ANTLR_LIB "")

include_directories (${ANTLR_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_definitions(-DANTLR4CPP_STATIC)
if(MSVC)
	add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING -D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# android has it's own specific CXXFLAGS ...
if(CMAKE_CXX_COMPILER_ID STREQUAL Clang AND NOT ANDROID)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL Clang )
add_definitions(-Wno-extra-tokens)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
 set(ANTLR_LIB ${ANTLR_LIB} pthread)
endif()
 

if(NOT APPLE)
 if(WIN32)
  set(ANTLR_LIB ${ANTLR_LIB} antlr4_static  )  
 else()
  set(ANTLR_LIB ${ANTLR_LIB} localuuid antlr4_static  ) 
 endif()
else()
#fixme : On Apple platform
 find_package(COREFOUNDATION_LIBRARY CoreFoundation REQUIRED)
 set(ANTLR_LIB ${ANTLR_LIB} antlr4_static   ${COREFOUNDATION_LIBRARY})
endif(NOT APPLE)


add_subdirectory (libs)
add_subdirectory(app)
add_subdirectory(test/parsing)