cmake_minimum_required(VERSION 2.8.12)

project(skia_dep_fetcher)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
find_package(Qt5Core)

add_subdirectory (libs)
set (SRCS localsourcesfetcher.cpp resitem.qrc sinkrongithandler.cpp)
add_executable(${PROJECT_NAME} "main.cpp"
            ${SRCS})

target_link_libraries(${PROJECT_NAME} Qt5::Core elzip)
