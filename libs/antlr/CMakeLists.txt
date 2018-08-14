set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/runtime/Cpp)

include_directories(
  ${ROOT_SRC_DIR}/lib/libuuid
  ${PROJECT_SOURCE_DIR}/runtime/src
  ${PROJECT_SOURCE_DIR}/runtime/src/atn
  ${PROJECT_SOURCE_DIR}/runtime/src/dfa
  ${PROJECT_SOURCE_DIR}/runtime/src/misc
  ${PROJECT_SOURCE_DIR}/runtime/src/support
  ${PROJECT_SOURCE_DIR}/runtime/src/tree
  ${PROJECT_SOURCE_DIR}/runtime/src/tree/pattern
  ${PROJECT_SOURCE_DIR}/runtime/src/tree/xpath
)

file(GLOB libantlrcpp_SRC
  ${PROJECT_SOURCE_DIR}/runtime/src/*.cpp
  ${PROJECT_SOURCE_DIR}/runtime/src/atn/*.cpp
  ${PROJECT_SOURCE_DIR}/runtime/src/dfa/*.cpp
  ${PROJECT_SOURCE_DIR}/runtime/src/misc/*.cpp
  ${PROJECT_SOURCE_DIR}/runtime/src/support/*.cpp
  ${PROJECT_SOURCE_DIR}/runtime/src/tree/*.cpp
  ${PROJECT_SOURCE_DIR}/runtime/src/tree/pattern/*.cpp
  ${PROJECT_SOURCE_DIR}/runtime/src/tree/xpath/*.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  add_definitions( "/wd4251")
else()
  add_definitions( "-Wno-overloaded-virtual")
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_definitions( "-Wno-dollar-in-identifier-extension -Wno-four-char-constants")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Intel")
  add_definitions( "-Wno-multichar")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  add_definitions("-MP")
endif()

add_library(antlr4_static STATIC ${libantlrcpp_SRC})
