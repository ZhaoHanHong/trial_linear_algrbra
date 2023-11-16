cmake_minimum_required(VERSION 3.5)

project(Matrix)#project name can be abitary

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")# help to debug

add_executable(trial trial.cpp)# add executable file, don't change
add_executable(calculate calculate.cpp)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
