#include "Application.hpp"

#include "EventSystem.hpp"
#include "Input.hpp"
#include "Log.hpp"
#include "Mesh.hpp"
#include "Utils.hpp"
#include "Window.hpp"

namespace Kea
{

void Application::Run()
{
    StartUp();

    Window window(1280, 720, "Hello Window");
    window.SetVerticalSync(true);
    window.SetRawMouseMotion(true);
    while (!window.ShouldClose())
    {
        window.PollEvents();
        window.BeginFrame();

        // renderer.SubmitDrawCall(mesh, shader, projection);

        window.EndFrame();
    }

    ShutDown();
}

void Application::StartUp()
{
    Kea::Log::Initialize();
    Kea::Input::Instance().Initialize();

    renderer = Renderer();

    LoadTestResources();
}

void Application::LoadTestResources()
{
    if (auto mrd = ObjLoader::LoadFromFile("assets/meshes/cube.obj"))
    {
        mesh = Mesh(mrd.value());
        // mesh.setupMesh();

        KEA_LOG_INFO("Application", "Successfully loaded mesh.");
        for (auto v : mesh.vertices)
        {
            KEA_LOG_INFO(
                "Test",
                "pos: ({:>8.3f},{:>8.3f},{:>8.3f}), norm: ({:>8.3f},{:>8.3f},{:>8.3f}), uv: ({:>8.3f},{:>8.3f})",
                v.pos.x, v.pos.y, v.pos.z, v.norm.x, v.norm.y, v.norm.x, v.uv.x, v.uv.y);
        }
    }
    if (auto mrd = ObjLoader::LoadFromFile("assets/meshes/cube-tex.obj"))
    {
        mesh = Mesh(mrd.value());
        // mesh.setupMesh();

        KEA_LOG_INFO("Application", "Successfully loaded mesh.");
        for (auto v : mesh.vertices)
        {
            KEA_LOG_INFO(
                "Test",
                "pos: ({:>8.3f},{:>8.3f},{:>8.3f}), norm: ({:>8.3f},{:>8.3f},{:>8.3f}), uv: ({:>8.3f},{:>8.3f})",
                v.pos.x, v.pos.y, v.pos.z, v.norm.x, v.norm.y, v.norm.x, v.uv.x, v.uv.y);
        }
    }
}

void Application::ShutDown()
{
    // shut down systems
}

} // namespace Kea