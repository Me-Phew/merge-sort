cmake_minimum_required(VERSION 3.10)

project(MergeSort)

include_directories(src/app src/merge_sorter)

set(SOURCES src/main.cpp src/app/app.cpp src/merge_sorter/merge_sorter.cpp)

add_executable(MergeSort ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
