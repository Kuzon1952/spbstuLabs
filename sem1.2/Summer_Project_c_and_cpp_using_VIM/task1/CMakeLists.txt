cmake_minimum_required(VERSION 3.10)
project(StrlenProject C)

set(CMAKE_C_STANDARD 99)

# Optional: to make sure inlining doesn't interfere
add_definitions(-Wall)

# ==========================
# Build the static library
# ==========================
add_library(mystrlen_static STATIC strlen_iterative.c strlen_recursive.c)

# ==========================
# Build the shared library
# ==========================
add_library(mystrlen_shared SHARED strlen_iterative.c strlen_recursive.c)

# ==========================
# Test program using static linking
# ==========================
add_executable(test_static test_static.c)
target_link_libraries(test_static mystrlen_static)

# ==========================
# Test program using dynamic linking
# ==========================
add_executable(test_dynamic test_dynamic.c)
target_link_libraries(test_dynamic mystrlen_shared)

# ==========================
# Test program using dlopen
# ==========================
add_executable(test_dlopen test_dlopen.c)
target_link_libraries(test_dlopen dl)

# ==========================
# Include directory (if needed)
# ==========================
target_include_directories(test_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(test_dynamic PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(test_dlopen PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
