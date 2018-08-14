include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../libs/depsparser 
                 ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/antlr/runtime/Cpp/runtime/src 
                 ${CMAKE_CURRENT_SOURCE_DIR}/../../libs/depsparser/generated 
                 ${CMAKE_CURRENT_SOURCE_DIR}/../lib/include
                 ${CMAKE_CURRENT_SOURCE_DIR}/../../test/lib
                 )
             
set(SRCS parsingtest.cc)
add_compile_definitions (ROOT_TEST_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\") 
add_executable (parsingtest ${SRCS}  ${CMAKE_CURRENT_SOURCE_DIR}/../../test/lib/src/gtest-all.cc)

target_link_libraries(parsingtest depsparser ${ANTLR_LIB})
