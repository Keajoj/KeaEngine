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
};

} // namespace Kea
#endif /* KEA_ENGINE_APPLICATION_HPP */
