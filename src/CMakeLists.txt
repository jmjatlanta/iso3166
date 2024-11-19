cmake_minimum_required(VERSION 3.10)

project(iso3166_src)

add_library( ${PROJECT_NAME}
    iso3166.cpp
)

target_include_directories( ${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../csv-parser
)

