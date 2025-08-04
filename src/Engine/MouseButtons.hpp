#ifndef KEA_ENGINE_MOUSEBUTTONS_HPP
#define KEA_ENGINE_MOUSEBUTTONS_HPP

#include "glfw/glfw3.h"

namespace Kea
{

enum class MouseButton
{
    MOUSE_1 = GLFW_MOUSE_BUTTON_1,
    MOUSE_2 = GLFW_MOUSE_BUTTON_2,
    MOUSE_3 = GLFW_MOUSE_BUTTON_3,
    MOUSE_4 = GLFW_MOUSE_BUTTON_4,
    MOUSE_5 = GLFW_MOUSE_BUTTON_5,
    MOUSE_6 = GLFW_MOUSE_BUTTON_6,
    MOUSE_7 = GLFW_MOUSE_BUTTON_7,
    MOUSE_8 = GLFW_MOUSE_BUTTON_8,
    MOUSE_LAST = GLFW_MOUSE_BUTTON_LAST,
    MOUSE_LEFT = GLFW_MOUSE_BUTTON_LEFT,
    MOUSE_RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
    MOUSE_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
};

inline const char* ToString(MouseButton button)
{
    switch (button)
    {
    case MouseButton::MOUSE_LEFT:
        return "MOUSE_LEFT";
    case MouseButton::MOUSE_RIGHT:
        return "MOUSE_RIGHT";
    case MouseButton::MOUSE_MIDDLE:
        return "MOUSE_MIDDLE";
    case MouseButton::MOUSE_4:
        return "MOUSE_4";
    case MouseButton::MOUSE_5:
        return "MOUSE_5";
    case MouseButton::MOUSE_6:
        return "MOUSE_6";
    case MouseButton::MOUSE_7:
        return "MOUSE_7";
    case MouseButton::MOUSE_8:
        return "MOUSE_8";
    default:
        return "UNKNOWN_MOUSE_BUTTON";
    }
}
} // namespace Kea

#endif /* KEA_ENGINE_MOUSEBUTTONS_HPP */
