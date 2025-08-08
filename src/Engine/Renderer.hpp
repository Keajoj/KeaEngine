#ifndef KEA_ENGINE_RENDERER_HPP
#define KEA_ENGINE_RENDERER_HPP

#include "Core.hpp"
#include "Shader.hpp"

class Renderer
{
  public:
    struct MeshData
    {
        std::vector<glm::vec3> positions;
        std::vector<glm::vec3> normals;
        std::vector<glm::vec2> texCoords;
        std::vector<unsigned int> indices;

        unsigned int VAO = 0;
        unsigned int EBO = 0;
        unsigned int VBO = 0;

        MeshData(std::vector<glm::vec3> pos, std::vector<glm::vec3> nor, std::vector<glm::vec2> tex,
                 std::vector<unsigned int> ind)
            : positions(pos), normals(nor), texCoords(tex), indices(ind) {};
    };

  public:
    std::vector<MeshData> Meshes;

  public:
    Renderer() = default;
    ~Renderer() = default;

    void Initialize();

    void SetupMesh(MeshData* meshData);
    void DestroyMesh(MeshData* meshData);

    void BeginFrame(glm::vec4 clearColor);
    void SubmitDrawCall(MeshData* meshData, Shader* shader, glm::mat4 projection);

    void ShutDown();
};

#endif /* KEA_ENGINE_RENDERER_HPP */
