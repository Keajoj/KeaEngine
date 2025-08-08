#ifndef KEA_ENGINE_MESH_HPP
#define KEA_ENGINE_MESH_HPP

#include "Core.hpp"
#include "ObjLoader.hpp"
#include "Utils.hpp"

class Mesh
{
  public:
    using Vertex = ObjLoader::Vertex;

  public:
    // std::vector<GLfloat> positions{};
    // std::vector<GLfloat> normals{};
    // std::vector<GLfloat> uvs{};

    std::vector<Vertex> vertices{};
    std::vector<GLuint> indices{};

  public:
    Mesh() {};
    Mesh(const ObjLoader::MeshRenderData& data) : vertices(data.vertices), indices(data.indices) {};
    ~Mesh() {};

  private:
    unsigned int VAO = 0;
    unsigned int EBO = 0;
    unsigned int VBO = 0;
};

#endif /* KEA_ENGINE_MESH_HPP */
