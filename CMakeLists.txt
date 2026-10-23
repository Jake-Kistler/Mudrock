cmake_minimum_required(VERSION 3.20)

project(Mudstone LANGUAGES CXX)

add_executable(mudstone
    src/main.cpp
    src/physics.cpp
)

target_compile_features(mudstone PRIVATE cxx_std_17)