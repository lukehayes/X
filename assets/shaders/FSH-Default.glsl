#version 460 core

in vec3 color;

uniform float time;

out vec4 FragColor;

void main()
{
	vec4 color = vec4(color, 1.0);

    FragColor = vec4(color);
} 
