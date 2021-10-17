#include "../../pch.h"

#include "render.h"

#include "quad.h"

namespace DragonFruit
{
	Quad::Quad(Texture& atlas, int posx, int posy, glm::vec3 position)
		: m_texture(atlas), m_posx(posx), m_posy(posy)
	{
		Render::NewVertex(this->Vertices);
		Render::NewIndex(this->Indices);
	}
};