#include "pch.h"

#include "scene.h"

#include "component.h"
#include "entity.h"
#include "app.h"

namespace Dragonfruit
{
	uint32_t Scene::AddEntity()
	{
		Entity* entity = new Entity{ m_registry.create(), this };
		m_entities[entity->m_id] = entity;

		m_entitycount++;
		return entity->m_id;
	}

	uint32_t Scene::AddEntity(const char* _texture, Vector2<float>& _pos, bool _control)
	{
		Entity* entity = new Entity{ m_registry.create(), this };
		m_entities[entity->m_id] = entity;

		entity->GetComponent<MeshComponent>().Mesh.SetTexture(_texture);
		entity->GetComponent<TransformComponent>().Position = { (_pos, 0.0f) };
		entity->GetComponent<NameComponent>().Name = "New Entity";
		entity->m_controllable = _control;

		m_entitycount++;
		return entity->m_id;
	}

	void Scene::ProcessEntities()
	{
		for (std::pair<uint32_t, Entity*> entity : m_entities)
		{
			Application::Get()->GetWindow().PassQuadToRenderer(entity.second->GetComponent<MeshComponent>().Mesh);

			if (entity.second->m_controllable) entity.second->HandleInputs();
		}
	}
}