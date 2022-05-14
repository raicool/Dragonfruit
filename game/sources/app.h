#pragma once

#include "system/entity.h"
#include "system/scene.h"
#include "graphics/quad.h"
#include "graphics/window.h"
#include "graphics/gui/hierarchy.h"

#include "system/debug.h"

namespace Dragonfruit
{
	class Application
	{
	public:
		void Update();
		bool IsRunning() const { return m_running; }

		static Application* Get() { return m_instance; };
		Window& GetWindow() { return m_window; }

		Application();

	private:
		friend class Window;

		using timer_highp = std::chrono::time_point<std::chrono::steady_clock>;
		using clock_highp = std::chrono::steady_clock;

		bool m_running = true;
		uint32_t m_players[4];

		uint64_t m_framerate;

		Window m_window;
		Scene m_scene;
		Hierarchy m_hierarchy;

	private:
		static Application* m_instance;
	};
}