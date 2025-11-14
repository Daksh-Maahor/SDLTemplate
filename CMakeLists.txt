cmake_minimum_required(VERSION 3.16)
project(PokeBattle VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2 and SDL2_image packages
find_package(SDL2 REQUIRED)
find_package(sdl2_image REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Window.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    ${SDL2_LIBRARIES}
    SDL2_image::SDL2_image
)

# Set compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Copy resources to build directory
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

# Print configuration info
message(STATUS "SDL2 found: ${SDL2_FOUND}")
message(STATUS "SDL2_image found: ${sdl2_image_FOUND}")
message(STATUS "SDL2 version: ${SDL2_VERSION}")

