#include "Input.hpp"
#include "Log.hpp"
#include "Window.hpp"

int main()
{
    Kea::Log::Init();
    Kea::Input::Instance().Initialize();
    Window window(1280, 720, "Hello Window");
    window.SetVerticalSync(true);
    while (!window.ShouldClose())
    {
        window.PollEvents();
        window.BeginFrame();

        window.EndFrame();
    }
}