file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS CONFIGURE_DEPENDS include/*.hpp)

add_library(KeaEngine STATIC
    ${ENGINE_SRC}
    ${ENGINE_HEADERS}
)

target_include_directories(KeaEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)