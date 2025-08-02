#include "Engine/Input.hpp"

#include "glm/glm.hpp"

#include <iostream>

namespace Kea
{
bool Input::IsKeyDown(KeyCode key)
{
}

bool Input::IsKeyPressed(KeyCode key)
{
}

bool Input::IsKeyReleased(KeyCode key)
{
}

bool Input::IsMouseButtonDown(MouseButton button)
{
}

bool Input::IsMouseButtonPressed(MouseButton button)
{
}

bool Input::IsMouseButtonReleased(MouseButton button)
{
}

glm::vec2 Input::GetMousePosition()
{
    return m_MousePos;
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    MouseButton mb = MouseButton(button);
    switch (mb)
    {

    case MouseButton::MOUSE_1:
        std::cout << "MOUSE_1\n";
        break;
    case MouseButton::MOUSE_2:
        std::cout << "MOUSE_2\n";
        break;
    case MouseButton::MOUSE_3:
        std::cout << "MOUSE_3\n";
        break;
    case MouseButton::MOUSE_4:
        std::cout << "MOUSE_4\n";
        break;
    case MouseButton::MOUSE_5:
        std::cout << "MOUSE_5\n";
        break;
    case MouseButton::MOUSE_6:
        std::cout << "MOUSE_6\n";
        break;
    case MouseButton::MOUSE_7:
        std::cout << "MOUSE_7\n";
        break;
    case MouseButton::MOUSE_8:
        std::cout << "MOUSE_8\n";
        break;
    }
}

void Input::CursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
    //
}

} // namespace Kea