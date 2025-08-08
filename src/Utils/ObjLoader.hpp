#ifndef KEA_UTILS_OBJLOADER_HPP
#define KEA_UTILS_OBJLOADER_HPP

#include "Core.hpp"

class ObjLoader
{
  public:
    struct Vertex
    {
        glm::vec3 pos;
        glm::vec3 norm;
        glm::vec2 uv;
    };

    struct MeshRenderData
    {
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
    };

    static std::optional<MeshRenderData> LoadFromFile(const std::string& filepath);
};

#endif /* KEA_UTILS_OBJLOADER_HPP */
