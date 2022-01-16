#include "pch.h"

namespace DragonFruit
{
	// Entity
	Entity::Entity(SDL_Texture* _texture, Vector2<float>& _pos, bool _controllable)
	{	
		this->m_Quad.SetTexture(_texture);
		this->m_Quad.GetRect() = { _pos.x, _pos.y };
		this->m_Quad.SetSize(this->GetSizeOfTexture<float>());

		this->m_Controllable = _controllable;

		static uint32_t counter = 0;
		this->m_Id = counter++;
		DF_LOG_INFO("Entity created at " << this->x << ", " << this->y);
	}
	
	Entity::~Entity() 
	{ 
		DF_LOG_INFO("Entity destroyed"); 
	}

	void Entity::AssignTexture(SDL_Texture* _texture)
	{
		this->m_Quad.SetTexture(_texture);
	}

	template<typename T>
    Vector2<T>& Entity::GetSizeOfTexture()
	{
		int32_t _checkw, _checkh;
		SDL_QueryTexture(this->m_Quad.GetTexture(), NULL, NULL, &_checkw, &_checkh);
		DF_LOG_DEBUG("Entities texture size " << _checkw << " " << _checkh);

		return Vector2<T>{ (T)_checkw, (T)_checkh };
	}

	void Entity::HandleInputs()
	{
		const uint8_t* _keyboard = SDL_GetKeyboardState(NULL);

		this->x += (-_keyboard[SDL_SCANCODE_A] + _keyboard[SDL_SCANCODE_D]);
		this->y += (-_keyboard[SDL_SCANCODE_W] + _keyboard[SDL_SCANCODE_S]);

		DF_LOG_DEBUG(this->x << ", " << this->y);
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
