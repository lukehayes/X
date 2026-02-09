#version 460 core

layout (location = 0) in vec3 vertex_position;

out vec3 color;

void main()
{
    gl_Position = vec4(vertex_position, 1.0f);
}
