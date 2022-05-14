#pragma once

#include "scene.h"

namespace Dragonfruit
{
	class Entity
	{
	public:
		uint32_t GetID() { return m_id; }
		
		void HandleInputs();

		template<typename T>
		T& AddComponent();

		template<typename T>
		T& GetComponent();

		Entity(entt::entity identifier, Scene* scene);
		
		// Copy
		Entity(Entity&, entt::entity identifier, Scene* scene);

		~Entity();

	protected:
		// Is entity handled by player keyboard/controller input?
		bool m_controllable = false;

		// Given at creation
		uint32_t m_id = 0;

		//
		entt::entity m_entityhandler;

		// Scene that the entity is assigned to
		Scene* m_scene = nullptr;

	private:
		friend class EntityManager;
		friend class Scene;
	};
}