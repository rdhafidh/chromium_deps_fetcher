include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/depsparser ${CMAKE_CURRENT_SOURCE_DIR}/../libs/unzipper 
                 ${CMAKE_CURRENT_SOURCE_DIR}/../libs/antlr/runtime/Cpp/runtime/src ${CMAKE_CURRENT_SOURCE_DIR}/../libs/depsparser/generated )

set (SRCS localsourcesfetcher.cpp  sinkrongithandler.cpp)

add_executable(${PROJECT_NAME} "main.cpp"
            ${SRCS})

target_link_libraries(${PROJECT_NAME} Qt5::Core elzip depsparser ${ANTLR_LIB})
