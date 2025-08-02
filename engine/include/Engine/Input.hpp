#ifndef KEA_ENGINE_INCLUDE_ENGINE_INPUT_HPP
#define KEA_ENGINE_INCLUDE_ENGINE_INPUT_HPP

#include "Engine/KeyCodes.hpp"
#include "Engine/MouseButtons.hpp"

#include "glm/glm.hpp"

namespace Kea
{
class Input
{
  public:
    static bool IsKeyDown(KeyCode key);
    static bool IsKeyPressed(KeyCode key);
    static bool IsKeyReleased(KeyCode key);
    static bool IsMouseButtonDown(MouseButton button);
    static bool IsMouseButtonPressed(MouseButton button);
    static bool IsMouseButtonReleased(MouseButton button);
    static glm::vec2 GetMousePosition();

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void CursorPositionCallback(GLFWwindow* window, double xPos, double yPos);

  private:
    static bool m_IsKeyDown;
    static bool m_IsKeyPressed;
    static bool m_IsKeyReleased;
    static bool m_IsMouseButtonDown;
    static bool m_IsMouseButtonPressed;
    static bool m_IsMouseButtonReleased;
    static glm::vec2 m_MousePos;
};
} // namespace Kea
#endif /* KEA_ENGINE_INCLUDE_ENGINE_INPUT_HPP */
