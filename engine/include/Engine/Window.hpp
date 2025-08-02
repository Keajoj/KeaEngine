#ifndef KEA_ENGINE_INCLUDE_ENGINE_WINDOW_HPP
#define KEA_ENGINE_INCLUDE_ENGINE_WINDOW_HPP

#define GLAD_GL_IMPLEMENTATION
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "glfw/glfw3.h"

#include <string>

class Window
{
  public:
    Window(int width, int height, const std::string title);
    ~Window();

    bool ShouldClose() const;
    void PollEvents() const;
    void BeginFrame(/*const glm::vec4 &clearColor*/);
    void EndFrame();

    GLFWwindow* GetGLFWwindow() const;

    void SetVerticalSync(bool enabled);
    bool IsVerticalSyncEnabled() const;

    void WaitEvents() const;
    void WaitEventsTimeout(double timeout) const;

    void SetCursorEnabled(bool enabled);
    bool IsCursorEnabled() const;
    void SetRawMouseMotion(bool useRawMouseMotion);
    bool IsRawMouseMotionEnabled() const;

  private:
    GLFWwindow* m_Window;
    bool m_VerticalSyncEnabled;
    bool m_CursorEnabled;
    bool m_RawMouseMotionEnabled;

  private:
    void InitGLFW(int width, int height, const std::string title);
    void InitGLAD();
    void InitImGui();
    void ShutdownImGui();

  private:
    void SetFramebufferSizeCallback(GLFWframebuffersizefun callback);
    void SetKeyCallback(GLFWkeyfun callback);
    void SetMousePosCallback(GLFWcursorposfun callback);
    void SetMouseButtonCallback(GLFWmousebuttonfun callback);

  private:
    static void error_callback(int error, const char* description);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif /* KEA_ENGINE_INCLUDE_ENGINE_WINDOW_HPP */
