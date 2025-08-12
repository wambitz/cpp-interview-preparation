cmake_minimum_required(VERSION 3.14)
project(CPPInterviewPrep)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags for better debugging and warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# C++ Topics Ordered from Simplest to Most Complex
add_executable(01_basics src/01_basics.cpp)
add_executable(02_pointers_references src/02_pointers_references.cpp)
add_executable(03_classes_objects src/03_classes_objects.cpp)
add_executable(04_const_correctness src/04_const_correctness.cpp)
add_executable(05_function_overloading src/05_function_overloading.cpp)
add_executable(06_operator_overloading src/06_operator_overloading.cpp)
add_executable(07_memory_management src/07_memory_management.cpp)
add_executable(08_static_keyword src/08_static_keyword.cpp)
add_executable(09_namespaces src/09_namespaces.cpp)
add_executable(10_inheritance src/10_inheritance.cpp)
add_executable(11_polymorphism src/11_polymorphism.cpp)
add_executable(12_virtual_functions src/12_virtual_functions.cpp)
add_executable(13_friend_functions src/13_friend_functions.cpp)
add_executable(14_casting src/14_casting.cpp)
add_executable(15_copy_semantics src/15_copy_semantics.cpp)
add_executable(16_exception_handling src/16_exception_handling.cpp)
add_executable(17_raii src/17_raii.cpp)
add_executable(18_smart_pointers src/18_smart_pointers.cpp)
add_executable(19_move_semantics src/19_move_semantics.cpp)
add_executable(20_auto_decltype src/20_auto_decltype.cpp)
add_executable(21_templates src/21_templates.cpp)
add_executable(22_lambda_functions src/22_lambda_functions.cpp)
add_executable(23_stl_containers src/23_stl_containers.cpp)
add_executable(24_preprocessor src/24_preprocessor.cpp)
add_executable(25_file_io src/25_file_io.cpp)
add_executable(26_multithreading src/26_multithreading.cpp)

# Link threading library for multithreading example
target_link_libraries(26_multithreading pthread)
