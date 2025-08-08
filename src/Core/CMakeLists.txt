file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS *.hpp)
file(GLOB_RECURSE CORE_SOURCE CONFIGURE_DEPENDS *.cpp)

add_library(Core STATIC ${CORE_HEADERS} ${CORE_SOURCE})

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    Core
    PUBLIC glad::glad
           glfw
           glm::glm
           spdlog::spdlog
           imgui::imgui
)
