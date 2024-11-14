cmake_minimum_required(VERSION 3.14)

project(MergeSort)

include_directories(src/app src/merge_sorter src/utils)

set(SOURCES src/main.cpp src/app/app.cpp 
    src/merge_sorter/merge_sorter.cpp
    src/utils/array_utils/array_utils.cpp
    src/utils/random_number_generator/random_number_generator.cpp
    )

add_executable(MergeSort ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
