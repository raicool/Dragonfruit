#pragma once

#include "texture.h"

namespace DragonFruit
{
	class Quad
	{
	public:

		glm::vec3 Position{ 0, 0, 0.1 };

		// Vertex position (0byte offset) -> Texture coords (12byte offset)
		std::vector<float> Vertices
		{
			Position.x + 1.0f, Position.y + 1.0f, Position.z + 0.0f, // 0 : top right
			(float)((m_posx + 1) * 16) / 256,
			(float)((m_posy + 1) * 16) / 256,

			Position.x + 1.0f, Position.y - 1.0f, Position.z + 0.0f, // 1 : bottom right
			(float)((m_posx + 1) * 16) / 256,
			(float)( m_posy      * 16) / 256,

			Position.x - 1.0f, Position.y - 1.0f, Position.z + 0.0f, // 2 : bottom left
			(float)( m_posx      * 16) / 256,
			(float)( m_posy      * 16) / 256,

			Position.x - 1.0f, Position.y + 1.0f, Position.z + 0.0f, // 3 : top left
			(float)( m_posx      * 16) / 256,
			(float)((m_posy + 1) * 16) / 256
		};

		std::vector<unsigned int> Indices
		{
			0, 2, 1,
			3, 2, 0
		};

	public:
		Quad(Texture& atlas, int posx, int posy, glm::vec3 position = glm::vec3(0));

		~Quad();

	private:
		Texture& m_texture;
		int m_posx, m_posy;
		int m_vbid, m_ibid;
	};
}
