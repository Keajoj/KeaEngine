#include "Shader.hpp"
#include "Log.hpp"

#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource)
{
    Shader::CompileFromSource(vertexShaderSource, fragmentShaderSource);
}

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    Shader::LoadFromFile(vertexPath, fragmentPath);
}

Shader::Shader(GLuint ID) : id(ID)
{
    KEA_LOG_INFO("Shader created with id: {}", (int) id);
}

Shader::~Shader()
{
    glDeleteShader(id);
}

void Shader::Use()
{
    glUseProgram(id);
}

Shader Shader::LoadFromFile(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertShaderSource, fragShaderSource;
    std::ifstream vertShaderFile, fragShaderFile;

    vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vertShaderFile.open(vertexPath.c_str());

        std::stringstream vertShaderStream;
        vertShaderStream << vertShaderFile.rdbuf();

        vertShaderFile.close();
        vertShaderSource = vertShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        KEA_LOG_ERROR("Unable to read shader file {}\n{}: {}", vertexPath, e.code().message(), e.what());
        vertShaderSource = "";
    }

    try
    {
        fragShaderFile.open(fragmentPath.c_str());

        std::stringstream fragShaderStream;
        fragShaderStream << fragShaderFile.rdbuf();

        fragShaderFile.close();
        fragShaderSource = fragShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        KEA_LOG_ERROR("Unable to read shader file {}\n{}: {}", fragmentPath, e.code().message(), e.what());
        fragShaderSource = "";
    }

    return Shader::CompileFromSource(vertShaderSource.c_str(), fragShaderSource.c_str());
}

Shader Shader::CompileFromSource(const char* vertexShaderSource, const char* fragmentShaderSource)
{
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShaderSource, NULL);
    glCompileShader(vertex);
    CheckCompileErrors(vertex, "VERTEX");

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragment);
    CheckCompileErrors(fragment, "FRAGMENT");

    GLuint ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    CheckCompileErrors(ID, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return Shader(ID);
}

void Shader::CheckCompileErrors(const GLuint shader, const std::string& type)
{
    int success;
    char infoLog[1024];

    if (type == "PROGRAM")
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            KEA_LOG_ERROR("Shader program linking error.");
        }
    }
    else
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            KEA_LOG_ERROR("{} shader compilation error.", type);
        }
    }
    if (!success)
    {
        KEA_LOG_TRACE(infoLog);
    }
}