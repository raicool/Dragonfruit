#pragma once

#include "type.h"

#include "debug.h"

namespace Dragonfruit
{
	class Entity;

	class Scene
	{
	public:
		[[nodiscard]] uint32_t AddEntity(const char* texture, Vector2<float> pos, bool controllable = false, const char* name = "Entity");
		[[nodiscard]] uint32_t AddEntity();
		[[nodiscard]] uint32_t AddEntity(Entity&);

		void DeleteEntity(Entity*);

		uint32_t GetEntityCount() { return m_entitycount; }

		void ProcessEntities();

		Scene() { DF_LOG_INFO("Scene created"); }
		~Scene() { DF_LOG_INFO("Scene destroyed"); }

	private:
		friend class Entity;
		friend class Hierarchy;

		std::unordered_map<uint32_t, Entity*> m_entities;
		uint32_t m_entitycount = 0;

		entt::registry m_registry;
	};
}