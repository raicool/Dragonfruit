#include "pch.h"
#include "graphics/quad.h"
#include "entity.h"
#include "graphics/render.h"

namespace DragonFruit
{
	Player::Player(Texture& texture)
		: m_model(texture, 0, 0) 
	{
		DF_LOG_TEXT("Entity " << m_MyID << " Created");
		Render::DrawQuad(m_model);
	}
	
	void Player::Move(float pos[3])
	{
		m_Position += Position3D{ pos[0], pos[1], pos[2] };
		m_model.Pos = m_Position;
	}
}