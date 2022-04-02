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

		AddComponent<MeshComponent>();
		AddComponent<TransformComponent>();
		AddComponent<NameComponent>();

		MeshComponent& meshcomp = GetComponent<MeshComponent>();
		meshcomp.Mesh.SetTexture("grid");

		TransformComponent& transcomp = GetComponent<TransformComponent>();
		transcomp.Scale = { (Utils::GetSizeOfTexture<float>("grid") * 4.0f, 0.0f) };

		NameComponent& namecomp = GetComponent<NameComponent>();
		namecomp.Name = "Entity";

		DF_LOG_TRACE("Entity created at {}, {}", meshcomp.Mesh.GetRect().x, meshcomp.Mesh.GetRect().y);
	}

	template<typename T>
	void Entity::AddComponent()
	{
		m_scene->m_registry.emplace<T>(m_entityhandler);
	}

	template<typename T>
	T Entity::GetComponent()
	{
		return m_scene->m_registry.get<T>(m_entityhandler);
	}

	void Entity::HandleInputs()
	{
		const uint8_t* _keyboard = SDL_GetKeyboardState(NULL);
		MeshComponent& meshcomp = GetComponent<MeshComponent>();

		meshcomp.Mesh.GetRect().x += (-_keyboard[SDL_SCANCODE_A] + _keyboard[SDL_SCANCODE_D]) * 5;
		meshcomp.Mesh.GetRect().y += (-_keyboard[SDL_SCANCODE_W] + _keyboard[SDL_SCANCODE_S]) * 5;
	}

	Entity::~Entity()
	{
		DF_LOG_TRACE("Entity destroyed");
	}
}
