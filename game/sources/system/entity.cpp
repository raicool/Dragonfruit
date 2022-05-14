#include "pch.h"

#include "entity.h"

#include "graphics/window.h"
#include "component.h"

#include "utils.h"
#include "debug.h"

namespace Dragonfruit
{
	// Entity
	Entity::Entity(entt::entity identifier, Scene* scene)
	{	
		m_entityhandler = identifier;
		m_scene = scene;
		m_id = scene->GetEntityCount();

		AddComponent<QuadComponent>().SetTexture("grid");
		AddComponent<NameComponent>().Name = "Entity";

		QuadComponent& quadcomp = GetComponent<QuadComponent>();
		Vector2<float> texsize = Utils::GetSizeOfTexture<float>("grid")*4.0f;
		quadcomp.GetRect().w = texsize.x;
		quadcomp.GetRect().h = texsize.y;
		DF_LOG_TRACE("Entity created at {}, {}", quadcomp.GetRect().x, quadcomp.GetRect().y);
	}

	Entity::Entity(Entity& entity, entt::entity identifier, Scene* scene)
	{
		m_entityhandler = identifier;
		m_scene = scene;
		m_id = scene->GetEntityCount();

		AddComponent<QuadComponent>() = entity.GetComponent<QuadComponent>();
		AddComponent<NameComponent>() = entity.GetComponent<NameComponent>();

		DF_LOG_TRACE("Entity {} copied", m_id);
	}

	template<typename T>
	T& Entity::AddComponent()
	{
		m_scene->m_registry.emplace<T>(m_entityhandler);
		return m_scene->m_registry.get<T>(m_entityhandler);
	}

	template<typename T>
	T& Entity::GetComponent()
	{
		return m_scene->m_registry.get<T>(m_entityhandler);
	}

	void Entity::HandleInputs()
	{
		const uint8_t* _keyboard = SDL_GetKeyboardState(NULL);
		QuadComponent& quadcomp = GetComponent<QuadComponent>();

		quadcomp.GetRect().x += (-_keyboard[SDL_SCANCODE_A] + _keyboard[SDL_SCANCODE_D]) * 5;
		quadcomp.GetRect().y += (-_keyboard[SDL_SCANCODE_W] + _keyboard[SDL_SCANCODE_S]) * 5;
	}

	Entity::~Entity()
	{
		DF_LOG_TRACE("Entity destroyed");
	}
}
