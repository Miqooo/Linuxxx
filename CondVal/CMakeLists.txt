cmake_minimum_required(VERSION 3.5)

project(CondVal)

file(GLOB source_files "./*.c")
add_executable(main ${source_files})

file(GLOB queue_files "./queue/*.c")
add_library(queue ${queue_files})
target_include_directories(queue PRIVATE "./include")

target_include_directories(main PRIVATE "./include")
target_link_libraries(main PRIVATE pthread)
target_link_libraries(main PRIVATE queue)