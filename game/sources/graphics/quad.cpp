#include "pch.h"

namespace DragonFruit
{
	Quad::Quad(Vector2 _pos, Vector2 _size)
		: m_Texture(Resources::Get().GetTexture("placeholder"))
	{
		m_Rect.x = _pos.x;
		m_Rect.y = _pos.y;
		m_Rect.w = _size.x;
		m_Rect.h = _size.y;
	}

	Quad::~Quad()
	{
	}
}
