cmake_minimum_required(VERSION 3.5)

project(fork_example)

file(GLOB fork_example_files "./*.c")
add_executable(forker ${fork_example_files})