cmake_minimum_required(VERSION 3.15)
project(KeaEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For IDEs, clangd, etc.


add_subdirectory(engine)