#version 410 core
out vec4 FragColor;

in vec3 vPos;
in vec3 vColor;
in vec2 vTexCoord;

uniform sampler2D uTexture;

void main() {
    FragColor = vec4(vColor, 1.0);
}