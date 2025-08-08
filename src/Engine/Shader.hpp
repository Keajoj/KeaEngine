//===----------------------------------------------------------------------===//
//
// Part of Kea Engine
// Released under the MIT License
//
//===----------------------------------------------------------------------===//
///
/// @file Shader.hpp
/// Header file for basic starting implementation of a Shader object, which
/// handles the creation of OpenGL shader programs by loading source code
/// files and compiling them. This class also handles the setting of uniforms
/// specified in the shader.
///
//===----------------------------------------------------------------------===//
#ifndef KEA_ENGINE_SHADER_HPP
#define KEA_ENGINE_SHADER_HPP

#include "glad/glad.h"

#include <string>

class Shader
{
  public:
    GLuint id;
    Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void Use();

  private:
    Shader(GLuint ID);

  private:
    Shader LoadFromFile(const std::string& vertexPath, const std::string& fragmentPath);
    Shader CompileFromSource(const char* vertexShaderSource, const char* fragmentShaderSource);
    void CheckCompileErrors(const GLuint shader, const std::string&);
};

#endif /* KEA_ENGINE_SHADER_HPP */
