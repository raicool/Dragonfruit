#include "pch.h"

namespace DragonFruit
{
	// Entity
	Entity::Entity(Texture* _texture, Vector2& _pos, Vector2& _size)
	{
		this->m_Quad.GetRect() = { _pos.x, _pos.y, _size.x, _size.y };
		this->AssignTexture(_texture);

		static uint32_t counter = 0;
		this->m_Id = counter++;
		DF_LOG_INFO("Entity created");
	}
	
	Entity::~Entity() 
	{ 
		DF_LOG_INFO("Entity destroyed"); 
	}

	void Entity::AssignTexture(Texture* _texture)
	{
		this->m_Quad.SetTexture(_texture);
	}

	void Entity::HandleInputs()
	{
		const uint8_t* _keyboard = SDL_GetKeyboardState(NULL);

		this->x += (-_keyboard[SDL_SCANCODE_A] + _keyboard[SDL_SCANCODE_D]);
		this->y += (-_keyboard[SDL_SCANCODE_W] + _keyboard[SDL_SCANCODE_S]);
	}

	// Entity Manager
	void EntityManager::AddEntity(Entity* entity)
	{
		m_Entities.push_back(entity);
	}

	void EntityManager::Kill(uint32_t id)
	{
		for (size_t i = 0; i < m_Entities.size(); ++i)
		{
			if (m_Entities[i]->GetID() == id) {
				delete m_Entities[i];
				m_Entities.erase(m_Entities.begin() + i);
				return;
			}
		}
	}

	void EntityManager::Process(Window& _window)
	{
		for (Entity* entity : m_Entities)
		{
			_window.PassQuadToRenderer(entity->GetQuad());

			if (entity->m_Controllable) entity->HandleInputs();
		}
	}

	EntityManager& EntityManager::Get() 
	{
		static EntityManager _instance;
		return _instance;
	}
}
