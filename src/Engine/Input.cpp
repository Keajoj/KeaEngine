#include "Input.hpp"
#include "Log.hpp"
#include "LogMacros.hpp"
#include "glm/glm.hpp"

namespace Kea
{

Input& Input::Instance()
{
    static Input instance;
    return instance;
}

void Input::Initialize()
{
    Instance();
    for (auto& ks : keys_)
    {
        ks = KeyStatus();
    }
    for (auto& bs : mouseButtons_)
    {
        bs = ButtonStatus();
    }
    Input::Instance().m_ScrollOffset = glm::vec2();
}

void Input::Update()
{
    for (auto& ks : keys_)
    {
        ks.previous = ks.current;
    }
    for (auto& bs : mouseButtons_)
    {
        bs.previous = bs.current;
    }
    Input::Instance().m_ScrollOffset = glm::vec2();
}

bool Input::IsKeyDown(KeyCode key) const
{
    return keys_[(int) key].current;
}

bool Input::WasKeyPressed(KeyCode key) const
{
    return keys_[(int) key].current && !keys_[(int) key].previous;
}

bool Input::WasKeyReleased(KeyCode key) const
{
    return keys_[(int) key].previous && !keys_[(int) key].current;
}

bool Input::IsMouseButtonDown(MouseButton button) const
{
    return mouseButtons_[(int) button].current;
}

bool Input::WasMouseButtonPressed(MouseButton button) const
{
    return mouseButtons_[(int) button].current && !mouseButtons_[(int) button].previous;
}

bool Input::WasMouseButtonReleased(MouseButton button) const
{
    return mouseButtons_[(int) button].previous && !mouseButtons_[(int) button].current;
}

glm::vec2 Input::GetMousePosition() const
{
    return m_MousePosCurrent;
}

glm::vec2 Input::GetMouseDelta() const
{
    return m_MousePosCurrent - m_MousePosPrevious;
}

glm::vec2 Input::GetScrollOffset() const
{
    return m_ScrollOffset;
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key < 0 || key > (int) KeyCode::LAST)
    {
        return; // KeyCode out of range
    }
    auto& ks = Input::Instance().keys_[key];
    ks.previous = ks.current;
    ks.current = (action != GLFW_RELEASE) ? true : false;

    if (ks.current && !ks.previous)
    {
        // Dispatch KeyPressedEvent
        KEA_LOG_INFO("Input", "KeyPressedEvent: {}", ToString((KeyCode) key));
    }
    else if (!ks.current && ks.previous)
    {
        // Dispatch KeyReleasedEvent
        KEA_LOG_INFO("Input", "KeyReleasedEvent: {}", ToString((KeyCode) key));
    }
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button < 0 || button > (int) MouseButton::MOUSE_LAST)
    {
        return; // MouseButton out of range
    }
    auto& bs = Input::Instance().mouseButtons_[button];
    bs.previous = bs.current;
    bs.current = (action != GLFW_RELEASE) ? true : false;

    if (bs.current && !bs.previous)
    {
        // Dispatch MouseButtonPressedEvent
        KEA_LOG_INFO("Input", "MouseButtonPressedEvent: {}", ToString((MouseButton) button));
    }
    else if (!bs.current && bs.previous)
    {
        // Dispatch MouseButtonReleasedEvent
        KEA_LOG_INFO("Input", "MouseButtonReleasedEvent: {}", ToString((MouseButton) button));
    }
}

void Input::CursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
    Input& input = Input::Instance();
    input.m_MousePosPrevious = input.m_MousePosCurrent;
    input.m_MousePosCurrent = glm::vec2(xPos, yPos);
    glm::vec2 delta =
        glm::vec2(xPos - Input::Instance().m_MousePosPrevious.x, yPos - Input::Instance().m_MousePosPrevious.y);

    // Dispatch CursorMoveEvent
    KEA_LOG_INFO("Input", "CursorMoveEvent: pos({:>8.3f},{:>8.3f}) delta({:>8.3f},{:>8.3f})", xPos, yPos, delta.x,
                 delta.y);

    // ? Should we send current position and delta, or current position and last position ?
}

void Input::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    Input::Instance().m_ScrollOffset = glm::vec2(xoffset, yoffset);

    // Dispatch ScrollEvent
    KEA_LOG_INFO("Input", "ScrollEvent: {} {}", xoffset, yoffset);
}

} // namespace Kea