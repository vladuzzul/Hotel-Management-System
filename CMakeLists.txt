cmake_minimum_required(VERSION 3.10)

project(HotelManagementSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(Hotel_Management_System ${SOURCES})

# Include directories
target_include_directories(Hotel_Management_System PRIVATE src)

# Create the database directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/database)

# Add platform-specific configurations
if(WIN32)
    target_compile_definitions(Hotel_Management_System PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(Hotel_Management_System PRIVATE PLATFORM_MAC)
elseif(UNIX)
    target_compile_definitions(Hotel_Management_System PRIVATE PLATFORM_LINUX)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_libraries(Hotel_Management_System PRIVATE stdc++fs)
endif()
