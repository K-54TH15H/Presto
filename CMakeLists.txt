cmake_minimum_required(VERSION 3.23)
# Project Name - Presto
project(Presto)

add_executable(${PROJECT_NAME})

# Header Directories included
include_directories(include/)

target_sources(${PROJECT_NAME}
    PRIVATE
	src/main.cpp
)
