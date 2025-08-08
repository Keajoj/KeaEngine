file(GLOB_RECURSE UTILS_HEADERS CONFIGURE_DEPENDS *.hpp)
file(GLOB_RECURSE UTILS_SOURCE CONFIGURE_DEPENDS *.cpp)

add_library(Utils STATIC ${UTILS_HEADERS} ${UTILS_SOURCE})

target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    Utils
    PUBLIC Core
           glad::glad
           glfw
           glm::glm
           spdlog::spdlog
           imgui::imgui
)
