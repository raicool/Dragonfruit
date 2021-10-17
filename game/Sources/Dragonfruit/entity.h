#pragma once
#include "Graphics/quad.h"

namespace DragonFruit
{
	class SimpleEntity
	{
	protected:
		using Position3D = glm::vec<3, float, glm::highp>;
		using Position2D = glm::vec<2, float, glm::highp>;

		Position3D m_Position;
	public:
		const Position3D Pos() { return m_Position; }
	};

	class Player : SimpleEntity
	{
	private:
		Quad m_model;
	public:
		void Move(float* pos = 0);

		virtual Position3D Pos() { return m_model.Position;  }
		
		Player(Texture& texture);
	};
}