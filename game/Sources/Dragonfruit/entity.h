#pragma once
#include "Graphics/quad.h"

namespace DragonFruit
{
	static uint32_t EntityCount;

	class SimpleEntity
	{
	protected:
		using Position3D = glm::vec<3, float, glm::highp>;
		using Position2D = glm::vec<2, float, glm::highp>;

		Position3D m_Position{0};
		uint32_t m_MyID;
	public:
		const Position3D& Pos() { return m_Position; }
		const uint32_t GetID() { return m_MyID; }

		SimpleEntity() 
		{ 
			EntityCount++; 
			m_MyID = EntityCount; 
		}
	};

	class Player : SimpleEntity
	{
	private:
		Quad m_model;

	public:
		void Move(float pos[3]);

		virtual Position3D& Pos() { return m_model.Pos; }
		Quad& GetQuad() { return m_model; }
		
		Player(Texture& texture);
	};
}