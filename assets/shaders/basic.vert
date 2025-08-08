#version 410 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

out vec3 vPos;
out vec3 vColor;
out vec2 vTexCoord;

void main() {
    vPos = aPos;
    vTexCoord = aTexCoord;
    vColor = vec3(aTexCoord);
    gl_Position = uProjection * uView * uModel * vec4(aPos, 1.0);
}