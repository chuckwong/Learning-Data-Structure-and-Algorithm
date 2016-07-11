cmake_minimum_required(VERSION 3.5)
project(Learning_Data_Structure_and_Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

ADD_SUBDIRECTORY(Linear)

set(SOURCE_FILES main.c)
add_executable(Learning_Data_Structure_and_Algorithm ${SOURCE_FILES})