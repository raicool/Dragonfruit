#include "pch.h"

namespace DragonFruit
{
	EntityManager& EntityManager::Get() {
		static EntityManager instance;
		return instance;
	}

	// Entity
	Entity::Entity(Vector2 _pos, Vector2 _size)
		: m_Quad(_pos, _size)
	{
		static uint32_t counter = 0;
		this->m_Id = counter++;
		DF_LOG_INFO("Entity created");
	}
	
	Entity::~Entity() 
	{ 
		DF_LOG_INFO("Entity destroyed"); 
	}

	// Player
	Player::Player(Texture& _texture, Vector2& _pos, Vector2& _size) 
		: Entity(_pos, _size)
	{
		this->AssignTexture(_texture);
	}

	void Player::AssignTexture(Texture& _texture)
	{
		this->m_Quad.SetTexture(_texture);
	}

	void Player::HandleInputs()
	{
		const uint8_t* _keyboard = SDL_GetKeyboardState(NULL);

		this->x += (-_keyboard[SDL_SCANCODE_A] + _keyboard[SDL_SCANCODE_D]) * this->m_Speed;
		this->y += (-_keyboard[SDL_SCANCODE_W] + _keyboard[SDL_SCANCODE_S]) * this->m_Speed;
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
			_window.PassQuadToRenderer(entity->m_Quad);
		}
	}
}
