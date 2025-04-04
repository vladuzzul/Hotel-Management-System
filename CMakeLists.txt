cmake_minimum_required(VERSION 3.10)

project(HotelManagementSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(Hotel_Room_Rezervation_Manager ${SOURCES})

# Include directories
target_include_directories(Hotel_Room_Rezervation_Manager PRIVATE src)

# Add platform-specific configurations
if(WIN32)
    target_compile_definitions(Hotel_Room_Rezervation_Manager PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(Hotel_Room_Rezervation_Manager PRIVATE PLATFORM_MAC)
elseif(UNIX)
    target_compile_definitions(Hotel_Room_Rezervation_Manager PRIVATE PLATFORM_LINUX)
endif()

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test executable
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(HotelManagementTests ${TEST_SOURCES})
target_link_libraries(HotelManagementTests gtest gtest_main)
target_include_directories(HotelManagementTests PRIVATE src)

# Add test target
add_test(NAME HotelManagementTests COMMAND HotelManagementTests)
