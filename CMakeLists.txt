cmake_minimum_required(VERSION 3.14)
project(DeepLearning)

set(CMAKE_C_STANDARD 90)

add_executable(DeepLearning main.c)

target_link_libraries(DeepLearning -lm )