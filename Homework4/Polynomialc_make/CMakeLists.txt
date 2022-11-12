cmake_minimum_required(VERSION 3.5)

project(polynomial)

add_executable(polynomial main.cc polynomial.cc)

target_include_directories(polynomial PRIVATE)