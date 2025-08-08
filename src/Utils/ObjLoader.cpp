#include "ObjLoader.hpp"

#include <fstream>
#include <sstream>

std::optional<ObjLoader::MeshRenderData> ObjLoader::LoadFromFile(const std::string& filepath)
{
    struct MeshData
    {
        std::string name{};
        std::vector<glm::vec3> positions{};
        std::vector<glm::vec3> normals{};
        std::vector<glm::vec2> uvs{};
        std::vector<std::array<glm::ivec3, 3>> faces{};
    };

    std::ifstream objFile(filepath.c_str());
    if (!objFile.is_open())
    {
        KEA_LOG_ERROR("Couldn't open file: {}", filepath);
        return std::nullopt;
    }
    std::string line;
    MeshData data{};
    uint lineNum = 0;
    ObjLoader::MeshRenderData mrd{};
    while (std::getline(objFile, line))
    {
        ++lineNum;

        if (line.empty() || line[0] == '#')
        {
            continue; // skip blank lines and comments
        }

        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v")
        {
            glm::vec3 v(0.0f);
            iss >> v.x >> v.y >> v.z;
            data.positions.push_back(v);
        }
        else if (prefix == "vt")
        {
            glm::vec2 vt(0.0f);
            iss >> vt.x >> vt.y;
            data.uvs.push_back(vt);
        }
        else if (prefix == "vn")
        {
            glm::vec3 vn(0.0f);
            iss >> vn.x >> vn.y >> vn.z;
            data.normals.push_back(vn);
        }
        else if (prefix == "f")
        {
            // To parse face data, we first cache all tokens from the line

            std::string fv;
            int numVerts = 0;
            while (iss >> fv)
            {
                std::istringstream fvss(fv);
                std::string token;
                Vertex v;

                // Get position from index
                if (std::getline(fvss, token, '/') && !token.empty())
                {
                    int index = std::stoi(token) - 1;
                    if (index >= 0 && index < data.positions.size())
                    {
                        v.pos = data.positions[index];
                    }
                    else
                    {
                        KEA_LOG_WARN("Line {}: Out of bounds position index {} in face. Using zero vector.", lineNum,
                                     index + 1);
                        v.pos = glm::vec3(0.0f);
                    }
                }
                else
                {
                    v.pos = glm::vec3(0.0f);
                }

                // Get texture coordinates from index
                if (std::getline(fvss, token, '/') && !token.empty())
                {
                    int index = std::stoi(token) - 1;
                    if (index >= 0 && index < data.uvs.size())
                    {
                        v.uv = data.uvs[index];
                    }
                    else
                    {
                        KEA_LOG_WARN("Line {}: Out of bounds position index {} in face. Using zero vector.", lineNum,
                                     index + 1);
                        v.uv = glm::vec2(0.0f);
                    }
                }
                else
                {
                    v.uv = glm::vec2(0.0f);
                }

                // Get vertex normal from index
                if (std::getline(fvss, token, '/') && !token.empty())
                {
                    int index = std::stoi(token) - 1;
                    if (index >= 0 && index < data.normals.size())
                    {
                        v.norm = data.normals[index];
                    }
                    else
                    {
                        KEA_LOG_WARN("Line {}: Out of bounds position index {} in face. Using zero vector.", lineNum,
                                     index + 1);
                        v.norm = glm::vec3(0.0f);
                    }
                }
                else
                {
                    v.norm = glm::vec3(0.0f);
                }

                mrd.vertices.push_back(v);
                numVerts++;
            }
            if (numVerts < 3 || numVerts > 4)
            {
                KEA_LOG_WARN("Line {}: Abnormal number of vertices in face. Read {} vertices, expected 3 or 4. "
                             "Vertex will not be loaded.",
                             lineNum, numVerts);
                for (size_t i = 0; i < numVerts; ++i)
                {
                    mrd.vertices.pop_back(); // Remove the vertices from the wonky face
                }
                continue;
            }

            GLuint startIndex = mrd.vertices.size() - numVerts;
            mrd.indices.push_back(startIndex);
            mrd.indices.push_back(startIndex + 1);
            mrd.indices.push_back(startIndex + 2);
            if (numVerts == 4)
            {
                // Handle quad faces by adding the second triangle to define a quad
                mrd.indices.push_back(startIndex);
                mrd.indices.push_back(startIndex + 2);
                mrd.indices.push_back(startIndex + 3);
            }
        }
        else if (prefix == "o")
        {
            iss >> data.name;
        }
        else if (prefix == "g")
        {
            KEA_LOG_WARN("Line {}: Grouping not yet supported in .OBJ file loading.", lineNum);
        }
        else if (prefix == "mtllib")
        {
            KEA_LOG_WARN("Line {}: Material library references not yet supported in .OBJ file loading.", lineNum);
        }
        else if (prefix == "usemtl")
        {
            KEA_LOG_WARN("Line {}: Material loading not yet supported in .OBJ file loading.", lineNum);
        }
        else
        {
            KEA_LOG_WARN("Line {}: Encountered unknown prefix \"{}\" in .OBJ file", lineNum, prefix);
        }
    } /* end file line parsing while loop */

    KEA_LOG_INFO("Successfully loaded mesh {} from \"{}\"", data.name, filepath);
    return mrd;
}