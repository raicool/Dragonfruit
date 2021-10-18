#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextureCoords;
uniform mat4  u_VPMatrix;
uniform float u_Time;

out vec3 v_Position;
out vec2 v_TextureCoords;

void main() 
{
	v_Position = a_Position;
	v_TextureCoords = a_TextureCoords;

	gl_Position = u_VPMatrix * vec4(a_Position, 1);
}