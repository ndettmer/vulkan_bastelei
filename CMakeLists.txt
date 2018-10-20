cmake_minimum_required(VERSION 3.12)
project(vulkan01)

set(CMAKE_CXX_STANDARD 17)

add_executable(vulkan01 main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(vulkan01 ${SDL2_LIBRARIES})

find_package(Vulkan)

# get rid of annoying MSVC warnings.
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

include_directories(${Vulkan_INCLUDE_DIR})

set(ALL_LIBS  ${Vulkan_LIBRARY} )


set_target_properties(vulkan01 PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

target_link_libraries(vulkan01 ${ALL_LIBS} )