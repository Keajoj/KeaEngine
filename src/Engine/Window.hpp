#ifndef KEA_ENGINE_WINDOW_HPP
#define KEA_ENGINE_WINDOW_HPP

#include "glad/glad.h"
#include "glfw/glfw3.h"

#include <string>

class Window
{
  public:
    Window(int width, int height, const std::string title);
    ~Window();

    GLFWwindow* GetGLFWwindow() const;

    bool ShouldClose() const;
    void BeginFrame(/*const glm::vec4 &clearColor*/);
    void EndFrame();

    void PollEvents() const;
    void WaitEvents() const;
    void WaitEventsTimeout(double timeout) const;

    void SetVerticalSync(bool enabled);
    bool IsVerticalSyncEnabled() const;
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
    void RegisterInputEvents();

  private:
    void SetErrorCallback(GLFWerrorfun callback);
    void SetFramebufferSizeCallback(GLFWframebuffersizefun callback);
    void SetKeyCallback(GLFWkeyfun callback);
    void SetMousePosCallback(GLFWcursorposfun callback);
    void SetMouseButtonCallback(GLFWmousebuttonfun callback);
    void SetScrollCallback(GLFWscrollfun callback);

  private:
    static void error_callback(int error, const char* description);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif /* KEA_ENGINE_WINDOW_HPP */
