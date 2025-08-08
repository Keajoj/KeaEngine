//===----------------------------------------------------------------------===//
//
// Part of Kea Engine
// Released under the MIT License
//
//===----------------------------------------------------------------------===//
///
/// @file Application.hpp
/// Wraps application startup and shutdown code to help manage creation and
/// destruction of global objects and engine systems.
///
//===----------------------------------------------------------------------===//
#ifndef KEA_ENGINE_APPLICATION_HPP
#define KEA_ENGINE_APPLICATION_HPP

#include "Core.hpp"
#include "Mesh.hpp"
#include "Renderer.hpp"
namespace Kea
{

class Application
{
  public:
    Renderer renderer;

  public:
    Application() = default;
    ~Application() = default;

    void Run();

  private:
    void StartUp();
    void ShutDown();
    void LoadTestResources();

  private:
    Mesh mesh;
    // Shader shader;
    glm::mat4 projection;
};

} // namespace Kea
#endif /* KEA_ENGINE_APPLICATION_HPP */
