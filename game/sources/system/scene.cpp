#include "pch.h"

#include "scene.h"

#include "component.h"
#include "entity.h"
#include "app.h"

namespace Dragonfruit
{
	[[nodiscard]] uint32_t Scene::AddEntity()
	{
		Entity* entity = new Entity{ m_registry.create(), this };
		m_entities[entity->m_id] = entity;

		m_entitycount++;
		return entity->m_id;
	}

	[[nodiscard]] uint32_t Scene::AddEntity(const char* texture, Vector2<float> pos, bool control, const char* name)
	{
		Entity* entity = new Entity{ m_registry.create(), this };
		m_entities[entity->m_id] = entity;

		auto& quadcomp = entity->GetComponent<QuadComponent>();

		quadcomp.SetTexture(texture);
		
		Vector2<float> size = Utils::GetSizeOfTexture<float>("grid") * 4.0f;
		quadcomp.GetRect().w = size.x;
		quadcomp.GetRect().h = size.y;

		entity->GetComponent<NameComponent>().Name = name;
		entity->m_controllable = control;

		m_entitycount++;
		return entity->m_id;
	}

	[[nodiscard]] uint32_t Scene::AddEntity(Entity& otherentity)
	{
		Entity* entity = new Entity(otherentity, m_registry.create(), this);
		m_entities[entity->m_id] = entity;

		m_entitycount++;
		return entity->m_id;
	}

	void Scene::DeleteEntity(Entity* entity)
	{
		m_registry.destroy(entity->m_entityhandler);
	}

	void Scene::ProcessEntities()
	{
		for (auto& [id, entity] : m_entities)
		{
			Application::Get()->GetWindow().PassQuadToRenderer(entity->GetComponent<QuadComponent>());

			if (entity->m_controllable) entity->HandleInputs();
		}
	}
}