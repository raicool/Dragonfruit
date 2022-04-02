#pragma once

#include "system/scene.h"
#include "system/entity.h"
#include "system/layers.h"

namespace Dragonfruit
{
	class Hierarchy
	{
	public:
		void LinkScene(Scene* scene);

		void OnImGuiRender();

	private:
		void RenderNode(Entity* entity);

	private:
		Scene* m_scene = nullptr;
	};
}