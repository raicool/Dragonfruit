#include "pch.h"

#include "app.h"
#include "graphics/window.h"

#include "system/debug.h"

namespace Dragonfruit
{
	Application* Application::m_instance = nullptr;

	void Application::Start()
	{
		m_running = true;
		// Load Textures
		m_resources.LoadTexture("grid", "resources/tex/grid.png");

		m_hierarchy.LinkScene(&m_scene);

		m_players[1] = m_scene.AddEntity();
		m_players[2] = m_scene.AddEntity();
	}

	void Application::Update()
	{
		m_scene.ProcessEntities();
		m_window.Update(m_running);
	}

	Application::Application()
		: m_resources(Resource::Get())
	{
		m_instance = this;
		Start();
	}
}