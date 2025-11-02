cmake_minimum_required(VERSION 3.10)
project(task2_routes C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

add_executable(task2_routes
    main.c
    file_utils.c
)

find_package(Curses REQUIRED)
find_package(ZLIB REQUIRED)

include_directories(
    ${CURSES_INCLUDE_DIR}
    ${ZLIB_INCLUDE_DIRS}
    .
)

target_link_libraries(task2_routes
    ${CURSES_LIBRARIES}
    ${ZLIB_LIBRARIES}
)