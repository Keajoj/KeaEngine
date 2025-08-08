file(GLOB_RECURSE ENGINE_HEADERS CONFIGURE_DEPENDS *.hpp)
file(GLOB_RECURSE ENGINE_SOURCE CONFIGURE_DEPENDS *.cpp)

add_library(Engine STATIC ${ENGINE_HEADERS} ${ENGINE_SOURCE})

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    Engine
    PUBLIC Core
           Utils
           glad::glad
           glfw
           glm::glm
           spdlog::spdlog
           imgui::imgui
)
