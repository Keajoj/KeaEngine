cmake_minimum_required(VERSION 3.20)
project(KeaGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(GLFW_INCLUDE_NONE)

find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_subdirectory(src/Core)
add_subdirectory(src/Engine)
add_subdirectory(src/Utils)
add_subdirectory(tests)
