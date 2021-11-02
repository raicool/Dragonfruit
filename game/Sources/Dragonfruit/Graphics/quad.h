#pragma once

#include "texture.h"
#include "array.h"

namespace DragonFruit
{
	class Quad
	{
	public:

		glm::vec3 Pos{ 0, 0, 0.1 };

		std::vector<Vertex> Vertices
		{
			Vertex {
				Pos.x + 1.0f, Pos.y + 1.0f, Pos.z, // 0 : top right
				m_TexturePosX + 1 * 16 / 256,
				m_TexturePosY + 1 * 16 / 256
			},

			Vertex {
				Pos.x + 1.0f, Pos.y - 1.0f, Pos.z, // 1 : bottom right
				m_TexturePosX + 1 * 16 / 256,
				m_TexturePosY     * 16 / 256
			},

			Vertex {
				Pos.x - 1.0f, Pos.y - 1.0f, Pos.z, // 2 : bottom left
				m_TexturePosX * 16 / 256,
				m_TexturePosY * 16 / 256
			},

			Vertex {
				Pos.x - 1.0f, Pos.y + 1.0f, Pos.z, // 3 : top left
				m_TexturePosX     * 16 / 256,
				m_TexturePosY + 1 * 16 / 256
			},
		};

		std::vector<unsigned int> Indices
		{
			0, 2, 1,
			3, 2, 0
		};

	public:
		Quad(Texture& atlas, int posx, int posy, glm::vec3 position = glm::vec3(0));

	private:
		Texture& m_texture;
		float m_TexturePosX, m_TexturePosY;
		int m_vbid, m_ibid;
	};
}
