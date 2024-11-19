cmake_minimum_required(VERSION 3.10)

project(iso3166)

add_library( ${PROJECT_NAME}
    iso3166.cpp
    file_utils.cpp
)

target_include_directories( ${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../fast-cpp-csv-parser
)

