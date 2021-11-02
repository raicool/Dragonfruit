#version 330 core

out vec4 color;

uniform sampler2D Texture;

varying vec3 v_Position;
varying vec2 v_TextureCoords;

void main() 
{
	//color = texture(Texture, v_TextureCoords);
	color = vec4(1.0);
}