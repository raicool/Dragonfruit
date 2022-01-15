#pragma once

#define MAX_ENTITIES 1000

namespace DragonFruit
{
	class Entity
	{
	protected:
		friend class EntityManager;
		Quad m_Quad;
		uint32_t m_Id;

	public:
		virtual Quad& GetQuad() { return m_Quad; }
		float& x = this->m_Quad.GetRect().x;
		float& y = this->m_Quad.GetRect().y;
		float& w = this->m_Quad.GetRect().w;
		float& h = this->m_Quad.GetRect().h;

		uint32_t GetID() { return m_Id; }

		Entity(Vector2, Vector2);
		~Entity();
	};

	class Player : public Entity
	{
	protected:
		friend class EntityManager;
		uint32_t m_Speed;
		
	public:
		void HandleInputs();
		void AssignTexture(Texture&);

		Player(Texture&, Vector2&, Vector2&);
	};

	class EntityManager
	{
	private:
		static Player* m_EntityTable[MAX_ENTITIES];
		static uint32_t m_EntityCount;

	public:
		static void CreatePlayer(Texture&, Vector2 = { 0, 0 }, Vector2 = { 32, 32 });
		static void Kill(uint32_t _id);

		static void Process(Window&);

		static Player**  GetEntityTable() { return m_EntityTable; }
		static uint32_t& GetEntityCount() { return m_EntityCount; }
	};
}