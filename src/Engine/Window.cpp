#include "Window.hpp"
#include "Input.hpp"

#include <iostream>

Window::Window(int width, int height, const std::string title)
{
    InitGLFW(width, height, title);
    InitGLAD();
    InitImGui();
    RegisterInputEvents();
}

Window::~Window()
{
    ShutdownImGui();
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(m_Window);
}

void Window::PollEvents() const
{
    Kea::Input::Instance().Update();
    glfwPollEvents();
}

void Window::WaitEvents() const
{
    glfwWaitEvents();
}

void Window::WaitEventsTimeout(double timeout) const
{
    glfwWaitEventsTimeout(timeout);
}

void Window::BeginFrame(/*const glm::vec4 &clearColor*/)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::EndFrame()
{
    glfwSwapBuffers(m_Window);
}

void Window::SetVerticalSync(bool enabled)
{
    glfwSwapInterval(enabled ? 1 : 0);
    m_VerticalSyncEnabled = enabled;
}
bool Window::IsVerticalSyncEnabled() const
{
    return m_VerticalSyncEnabled;
}

void Window::SetCursorEnabled(bool enabled)
{
    m_CursorEnabled = enabled;
    glfwSetInputMode(m_Window, GLFW_CURSOR, m_CursorEnabled ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
}

bool Window::IsCursorEnabled() const
{
    return m_CursorEnabled;
}

void Window::SetRawMouseMotion(bool useRawMouseMotion)
{
    if (!glfwRawMouseMotionSupported())
    {
        std::cout << "Raw mouse motion is not supported on this device. Setting ignored.\n";
        return;
    }
    m_RawMouseMotionEnabled = useRawMouseMotion;
    glfwSetInputMode(m_Window, GLFW_RAW_MOUSE_MOTION, m_RawMouseMotionEnabled ? GLFW_TRUE : GLFW_FALSE);
}

bool Window::IsRawMouseMotionEnabled() const
{
    return m_RawMouseMotionEnabled;
}

void Window::InitGLFW(int width, int height, const std::string title)
{
    SetErrorCallback(error_callback); // We can actually call this BEFORE initialization
    if (!glfwInit())                  // Check for successful initialization
    {
        std::cerr << "GLFW Initialization failed. Program will close." << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create window, set window hints, and check that it exists
    m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!m_Window)
    {
        std::cerr << "Window or OpenGL context creation failed. Program will close." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
    SetFramebufferSizeCallback(framebuffer_size_callback);
}

void Window::InitGLAD()
{
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

void Window::InitImGui()
{
    // todo
}

void Window::ShutdownImGui()
{
    // todo
}

void Window::RegisterInputEvents()
{
    Kea::Input::Instance().Initialize();
    SetKeyCallback(Kea::Input::KeyCallback);
    SetMousePosCallback(Kea::Input::CursorPositionCallback);
    SetMouseButtonCallback(Kea::Input::MouseButtonCallback);
    SetScrollCallback(Kea::Input::ScrollCallback);
}

void Window::SetErrorCallback(GLFWerrorfun callback)
{
    glfwSetErrorCallback(callback);
}

void Window::SetFramebufferSizeCallback(GLFWframebuffersizefun callback)
{
    glfwSetFramebufferSizeCallback(m_Window, callback);
}

void Window::SetKeyCallback(GLFWkeyfun callback)
{
    glfwSetKeyCallback(m_Window, callback);
}

void Window::SetMousePosCallback(GLFWcursorposfun callback)
{
    glfwSetCursorPosCallback(m_Window, callback);
}

void Window::SetMouseButtonCallback(GLFWmousebuttonfun callback)
{
    glfwSetMouseButtonCallback(m_Window, callback);
}

void Window::SetScrollCallback(GLFWscrollfun callback)
{
    glfwSetScrollCallback(m_Window, callback);
}

void Window::error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
