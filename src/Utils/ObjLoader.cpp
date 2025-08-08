#include "ObjLoader.hpp"

#include <fstream>
#include <sstream>

std::optional<ObjLoader::MeshRenderData> ObjLoader::LoadFromFile(const std::string& filepath)
{
    struct MeshData
    {
        std::string name = "";
        std::vector<glm::vec3> positions{};
        std::vector<glm::vec3> normals{};
        std::vector<glm::vec2> uvs{};
        std::vector<std::array<glm::ivec3, 3>> faces{};
    };

    std::ifstream objFile(filepath.c_str());
    if (!objFile.is_open())
    {
        KEA_LOG_ERROR("Resources", "Couldn't open file: {}", filepath);
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
            KEA_LOG_INFO("Resources", "Line {}: Loaded {} vector ({},{},{}) into index {}", lineNum, "pos", v.x, v.y,
                         v.z, data.positions.size() - 1);
        }
        else if (prefix == "vt")
        {
            glm::vec2 vt(0.0f);
            iss >> vt.x >> vt.y;
            data.uvs.push_back(vt);
            KEA_LOG_INFO("Resources", "Line {}: Loaded {} vector ({},{}) into index {}", lineNum, "uv", vt.x, vt.y,
                         data.uvs.size() - 1);
        }
        else if (prefix == "vn")
        {
            glm::vec3 vn(0.0f);
            iss >> vn.x >> vn.y >> vn.z;
            data.normals.push_back(vn);
            KEA_LOG_INFO("Resources", "Line {}: Loaded {} vector ({},{},{}) into index {}", lineNum, "normal", vn.x,
                         vn.y, vn.z, data.normals.size() - 1);
        }
        else if (prefix == "f")
        {
            // To parse face data, we first cache all tokens from the line
            KEA_LOG_INFO("Resources",
                         "Line {}: Reading face data ====================================================", lineNum);
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
                        KEA_LOG_WARN("Resources",
                                     "Line {}: Out of bounds position index {} in face. Using zero vector.", lineNum,
                                     index + 1);
                        v.pos = glm::vec3(0.0f);
                    }
                }
                else
                {
                    v.pos = glm::vec3(0.0f);
                    KEA_LOG_WARN("Resources", "Line {}: Unable to read {} index in token {}. Using zero vector.",
                                 lineNum, "pos", numVerts + 1);
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
                        KEA_LOG_WARN("Resources",
                                     "Line {}: Out of bounds position index {} in face. Using zero vector.", lineNum,
                                     index + 1);
                        v.uv = glm::vec2(0.0f);
                    }
                }
                else
                {
                    v.uv = glm::vec2(0.0f);
                    KEA_LOG_WARN("Resources", "Line {}: Unable to read {} index in token {}. Using zero vector.",
                                 lineNum, "uv", numVerts + 1);
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
                        KEA_LOG_WARN("Resources",
                                     "Line {}: Out of bounds position index {} in face. Using zero vector.", lineNum,
                                     index + 1);
                        v.norm = glm::vec3(0.0f);
                    }
                }
                else
                {
                    v.norm = glm::vec3(0.0f);
                    KEA_LOG_WARN("Resources", "Line {}: Unable to read {} index in token {}. Using zero vector.",
                                 lineNum, "norm", numVerts + 1);
                }

                mrd.vertices.push_back(v);
                numVerts++;
                KEA_LOG_INFO("Resources", "Line {}: Added vertex [pos({},{},{}), uv({},{}), norm({},{},{})]", lineNum,
                             v.pos.x, v.pos.y, v.pos.z, v.uv.x, v.uv.y, v.norm.x, v.norm.y, v.norm.z);
            }
            if (numVerts < 3 || numVerts > 4)
            {
                KEA_LOG_WARN("Resources",
                             "Line {}: Abnormal number of vertices in face. Read {} vertices, expected 3 or 4. "
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
            KEA_LOG_INFO("Resources", "Line {}: Added indices: {}, {}, {}", lineNum, startIndex, startIndex + 1,
                         startIndex + 2);
            if (numVerts == 4)
            {
                // Handle quad faces by adding the second triangle to define a quad
                mrd.indices.push_back(startIndex);
                mrd.indices.push_back(startIndex + 2);
                mrd.indices.push_back(startIndex + 3);
                KEA_LOG_INFO("Resources", "Line {}: Added indices: {}, {}, {}", lineNum, startIndex, startIndex + 2,
                             startIndex + 3);
            }
            KEA_LOG_INFO("Resources", "Line {}: Finished reading {}.", lineNum, "face");
        }
        else if (prefix == "o")
        {
            iss >> data.name;
            KEA_LOG_INFO("Resources", "Line {}: Read name \"{}\"", lineNum, data.name);
        }
        else if (prefix == "g")
        {
            KEA_LOG_WARN("Resources", "Line {}: Grouping not yet supported in .OBJ file loading.", lineNum);
        }
        else if (prefix == "mtllib")
        {
            KEA_LOG_WARN("Resources", "Line {}: Material library references not yet supported in .OBJ file loading.",
                         lineNum);
        }
        else if (prefix == "usemtl")
        {
            KEA_LOG_WARN("Resources", "Line {}: Material loading not yet supported in .OBJ file loading.", lineNum);
        }
        else
        {
            KEA_LOG_WARN("Resources", "Line {}: Encountered unknown prefix \"{}\" in .OBJ file", lineNum, prefix);
        }
    } /* end file line parsing while loop */

    KEA_LOG_INFO("Resources", "Successfully loaded mesh {} from \"{}\"", data.name, filepath);
    return mrd;
}