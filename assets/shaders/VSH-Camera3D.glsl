#version 460 core

layout (location = 0) in vec3 vtx_position;
layout (location = 1) in vec3 vtx_color;

uniform mat4 u_projection;
uniform mat4 u_model;
uniform mat4 u_view;
uniform vec3 u_color;

out vec3 color;

void main()
{
	color = vtx_color;
    gl_Position = u_projection * u_view * u_model * vec4(vtx_position, 1.0f);
}
