cmake_minimum_required(VERSION 3.6)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/ext")

list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_LIST_DIR}/cmake"
    "${CMAKE_CURRENT_LIST_DIR}/ext/cmake"
    "${CMAKE_CURRENT_LIST_DIR}/ext/lib/cmake")

include_directories(BEFORE "${CMAKE_BINARY_DIR}/ext/include")

add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(test)
add_subdirectory(ext EXCLUDE_FROM_ALL)
