#pragma once
#include <vector>

#define MAX_ENTITIES 1000

namespace DragonFruit
{
	class Entity
	{
	protected:
		friend class EntityManager;
		Quad m_Quad;
		uint32_t m_Id;

		bool m_Controllable = false;

	public:
		Quad& GetQuad() { return m_Quad; }
		float& x = this->m_Quad.GetRect().x;
		float& y = this->m_Quad.GetRect().y;
		float& w = this->m_Quad.GetRect().w;
		float& h = this->m_Quad.GetRect().h;

		uint32_t GetID() { return m_Id; }

		Entity(Texture*, Vector2&, Vector2&);
		~Entity();

		void HandleInputs();
		void AssignTexture(Texture*);
	};

	class EntityManager
	{
	private:
		std::vector<Entity*> m_Entities;

	public:
		static EntityManager& Get();

		void Kill(uint32_t _id);

		void Process(Window&);

		void AddEntity(Entity*);

		auto& GetEntityTable() { return m_Entities; }
		auto  GetEntityCount() const { return m_Entities.size(); }
	};
}