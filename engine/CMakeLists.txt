file(GLOB_RECURSE 
    ENGINE_SRC 
    CONFIGURE_DEPENDS 
        src/*.cpp
)
file(GLOB_RECURSE 
    ENGINE_HEADERS 
    CONFIGURE_DEPENDS 
        include/*.hpp
)



find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_library(KeaEngine 
    STATIC
        ${ENGINE_SRC}
        ${ENGINE_HEADERS}
)

target_link_libraries(KeaEngine
    PUBLIC
        glfw3
        glad::glad
        glm::glm
)

target_include_directories(KeaEngine 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)