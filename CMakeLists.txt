cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

set (name Discrete_Optimisation)

project(${name})

file(GLOB TARGET_SRC "*.c*")
file(GLOB TARGET_HD "*.h*")
add_executable(${name} ${TARGET_SRC} ${TARGET_HD})
