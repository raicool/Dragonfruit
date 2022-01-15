#include "pch.h"

namespace DragonFruit
{
	Player*  EntityManager::m_EntityTable[MAX_ENTITIES];
	uint32_t EntityManager::m_EntityCount;

	// Entity
	Entity::Entity(Vector2 _pos, Vector2 _size)
		: m_Quad(_pos, _size)
	{
		this->m_Id = EntityManager::GetEntityCount();
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
	void EntityManager::CreatePlayer(Texture& _texture, Vector2 _pos, Vector2 _size)
	{
		m_EntityTable[m_EntityCount] = new Player(_texture, _pos, _size);
		m_EntityCount++;
	}

	void EntityManager::Kill(uint32_t _id)
	{
		delete m_EntityTable[_id];
	}

	void EntityManager::Process(Window& _window)
	{
		for (uint32_t i = 1; i <= m_EntityCount; i++)
		{
			_window.PassQuadToRenderer(m_EntityTable[i]->m_Quad);
		}
	}
}
