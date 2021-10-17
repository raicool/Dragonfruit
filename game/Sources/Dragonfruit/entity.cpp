#include "../pch.h"
#include "graphics/quad.h"
#include "entity.h"

namespace DragonFruit
{
	Player::Player(Texture& texture)
		: m_model(texture, 0, 0) {}
	
	void Player::Move(float pos[3])
	{
		m_Position += Position3D{ pos[0], pos[1], pos[2] };
		m_model.Position = m_Position;
	}
}