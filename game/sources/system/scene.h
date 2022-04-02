#pragma once

#include "type.h"

namespace Dragonfruit
{
	class Entity;

	class Scene
	{
	public:
		uint32_t AddEntity(const char* texture, Vector2<float>& pos, bool controllable = false);
		uint32_t AddEntity();

		uint32_t GetEntityCount() { return m_entitycount; }

		void ProcessEntities();

	private:
		friend class Entity;
		friend class Hierarchy;

		std::unordered_map<uint32_t, Entity*> m_entities;
		uint32_t m_entitycount;

		entt::registry m_registry;
	};
}