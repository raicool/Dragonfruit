#include "pch.h"

#include "hierarchy.h"

#include "system/component.h"

namespace Dragonfruit
{
	void Hierarchy::LinkScene(Scene* scene) 
	{
		m_scene = scene;
	}

	void Hierarchy::OnImGuiRender()
	{
		ImGui::Begin("Hierarchy");

		for (std::pair<uint32_t, Entity*> entity : m_scene->m_entities)
		{
			RenderNode(entity.second);
		}

		ImGui::End();
	}

	void Hierarchy::RenderNode(Entity* entity)
	{
		auto& name = entity->GetComponent<NameComponent>();

		ImGui::TreeNode(entity, name.Name.c_str());
	}
}