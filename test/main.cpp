#include "Engine/Window.hpp"

int main()
{
    Window window(1280, 720, "Hello Window");
    window.SetVerticalSync(true);
    while (!window.ShouldClose())
    {
        window.PollEvents();
        window.BeginFrame();

        window.EndFrame();
    }
}