cmake_minimum_required(VERSION 3.10)

project(DataStructures C)

# Add source files
file(GLOB SOURCES
    src/*.c
)

# Add include directories
include_directories(includes)

# Create the executable
add_executable(DataStructures ${SOURCES})

# Add compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Link external libraries (if needed)
target_link_libraries(DataStructures errors)
