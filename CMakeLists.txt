cmake_minimum_required(VERSION 3.12)
project(vulkan_bastelei)

set(CMAKE_CXX_STANDARD 17)

add_executable(vulkan_bastelei main.cpp Window.cpp Window.hpp)

find_package(glfw3 3.2.1 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(vulkan_bastelei glfw)

find_package(Vulkan)

# get rid of annoying MSVC warnings.
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

include_directories(${Vulkan_INCLUDE_DIR})

set(ALL_LIBS  ${Vulkan_LIBRARY})

set_target_properties(vulkan_bastelei PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

target_link_libraries(vulkan_bastelei ${ALL_LIBS} )