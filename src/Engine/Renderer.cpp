#include "Renderer.hpp"

// Renderer Flow

void Renderer::Initialize()
{
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // Enable face culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Enable blending for transparent objects
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    KEA_LOG_INFO("Renderer", "Renderer initialized with OpenGL {}",
                 reinterpret_cast<const char*>(glGetString(GL_VERSION)));
}

void Renderer::SetupMesh(MeshData* meshData)
{
    struct Vertex
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoord;
    };

    std::vector<Vertex> vertices;
    vertices.reserve(meshData->positions.size());

    for (size_t i = 0; i < meshData->positions.size(); i++)
    {
        vertices.push_back({meshData->positions[i],
                            i < meshData->normals.size() ? meshData->normals[i] : glm::vec3(0.0f),
                            i < meshData->texCoords.size() ? meshData->texCoords[i] : glm::vec2(0.0f)});
    }

    glGenVertexArrays(1, &meshData->VAO);
    glGenBuffers(1, &meshData->VBO);
    glGenBuffers(1, &meshData->EBO);

    glBindVertexArray(meshData->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, meshData->VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshData->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshData->indices.size() * sizeof(unsigned int), meshData->indices.data(),
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, Normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, TexCoord));

    glBindVertexArray(0);
}

void Renderer::BeginFrame(glm::vec4 clearColor)
{
    // Clear frame with clearColor specified earlier.
    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::SubmitDrawCall(MeshData* meshData, Shader* shader, glm::mat4 projection)
{

    glUseProgram(shader->id);

    glBindVertexArray(meshData->VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(meshData->indices.size()), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0); // unbind
}

void Renderer::DestroyMesh(MeshData* meshData)
{
    glDeleteVertexArrays(1, &meshData->VAO);
    glDeleteBuffers(1, &meshData->VBO);
    glDeleteBuffers(1, &meshData->EBO);
}

void Renderer::ShutDown()
{
    // Nothing critical yet.
}