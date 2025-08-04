#ifndef KEA_ENGINE_INPUT_HPP
#define KEA_ENGINE_INPUT_HPP

#include "KeyCodes.hpp"
#include "MouseButtons.hpp"

#include "glm/glm.hpp"

#include <array>

namespace Kea
{
class Input
{
  public:
    static Input& Instance();
    void Initialize();
    void Update();

  public:
    bool IsKeyDown(KeyCode key) const;
    bool WasKeyPressed(KeyCode key) const;
    bool WasKeyReleased(KeyCode key) const;
    bool IsMouseButtonDown(MouseButton button) const;
    bool WasMouseButtonPressed(MouseButton button) const;
    bool WasMouseButtonReleased(MouseButton button) const;
    glm::vec2 GetMousePosition() const;
    glm::vec2 GetMouseDelta() const;
    glm::vec2 GetScrollOffset() const;

  public:
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void CursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

  private:
    Input() = default;
    Input(const Input&) = delete;
    Input& operator=(const Input&) = delete;

  private:
    struct KeyStatus
    {
        bool current = false;
        bool previous = false;
    };
    using ButtonStatus = KeyStatus;
    static constexpr int NUM_KEYS = (int) KeyCode::LAST + 1;
    static constexpr int NUM_MBS = (int) MouseButton::MOUSE_LAST + 1;
    std::array<KeyStatus, NUM_KEYS> keys_{};
    std::array<ButtonStatus, NUM_MBS> mouseButtons_{};
    glm::vec2 m_MousePosCurrent{};
    glm::vec2 m_MousePosPrevious{};
    glm::vec2 m_ScrollOffset{};
};
} // namespace Kea

#endif /* KEA_ENGINE_INPUT_HPP */
