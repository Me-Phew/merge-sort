cmake_minimum_required(VERSION 3.14)

project(MergeSort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src/app src/merge_sorter src/utils)

# Main executable
# Create merge_sorter library
add_library(merge_sorter
    src/merge_sorter/merge_sorter.cpp
)

target_include_directories(merge_sorter PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/merge_sorter
)

# Main executable
set(SOURCES src/main.cpp src/app/app.cpp 
    src/merge_sorter/merge_sorter.cpp
    src/utils/array_utils/array_utils.cpp
    src/utils/random_number_generator/random_number_generator.cpp
    )

add_executable(MergeSort ${SOURCES})
target_link_libraries(MergeSort PRIVATE merge_sorter)

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Force Google Test to use dynamic runtime library
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)

    target_link_libraries(MergeSort PRIVATE merge_sorter)

    add_library(random_number_generator
        src/utils/random_number_generator/random_number_generator.cpp
    )

    target_include_directories(TestMergeSorter PRIVATE
        ${CMAKE_SOURCE_DIR}/src/utils/random_number_generator
    )
endif()
