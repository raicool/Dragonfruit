#pragma once

#include "system/entity.h"
#include "system/scene.h"
#include "graphics/quad.h"
#include "graphics/window.h"
#include "system/gui/hierarchy.h"

#include "system/debug.h"

namespace Dragonfruit
{
	class Application
	{
	public:
		void Start();
		void Update();

		Application();

		bool IsRunning() const { return m_running; }

		static Application* Get() { return m_instance; };

		Window& GetWindow() { return m_window; }

	private:
		friend class Window;

		bool m_running = false;
		uint32_t m_players[4];

		Window m_window;
		Resource& m_resources;

		Scene m_scene;
		Hierarchy m_hierarchy;

	private:
		static Application* m_instance;
	};
}