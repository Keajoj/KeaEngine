#include "Application.hpp"

#include "EventSystem.hpp"
#include "Input.hpp"
#include "Log.hpp"
#include "Window.hpp"

namespace Kea
{

void Application::Run()
{
    StartUp();

    Window window(1280, 720, "Hello Window");
    window.SetVerticalSync(true);
    window.SetRawMouseMotion(true);
    while (!window.ShouldClose())
    {
        window.PollEvents();
        window.BeginFrame();

        window.EndFrame();
    }

    ShutDown();
}

void Application::StartUp()
{
    Kea::Log::Initialize();
    Kea::Input::Instance().Initialize();
    renderer = Renderer();
}

void Application::ShutDown()
{
    // shut down systems
}

} // namespace Kea