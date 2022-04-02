#pragma once

#include "scene.h"

#define MAX_ENTITIES 1000

namespace Dragonfruit
{
	class Entity
	{
	public:
		uint32_t GetID() { return m_id; }
		
		void HandleInputs();

		template<typename T>
		void AddComponent();

		template<typename T>
		T GetComponent();

		Entity(entt::entity identifier, Scene* scene);
		Entity();
		~Entity();

	protected:
		// Is entity handled by player keyboard/controller input?
		bool m_controllable = false;

		// Given at creation
		uint32_t m_id;

		//
		entt::entity m_entityhandler;

		// Scene that the entity is assigned to
		Scene* m_scene = nullptr;

	private:
		friend class EntityManager;
		friend class Scene;
	};
}