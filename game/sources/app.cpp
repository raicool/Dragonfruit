#include "pch.h"

#include "app.h"

#include "system/debug.h"

namespace Dragonfruit
{
	Application* Application::m_instance = nullptr;

	Application::Application()
		: m_framerate(300)
	{
		m_instance = this;
		Resource::LoadTexture("grid", "resources/tex/grid.png");

		m_hierarchy.LinkScene(&m_scene);

		m_players[1] = m_scene.AddEntity("grid", { 0.0 }, true, "cool");
		m_players[2] = m_scene.AddEntity();
		m_players[3] = m_scene.AddEntity("grid", { 0.0 }, false, "cool2");
	}

	void Application::Update()
	{
		timer_highp begin = clock_highp::now();

		m_window.SetClearColor({ 32, 64, 128 });
		SDL_RenderClear(m_window.m_renderer);
		SDL_PollEvent(&m_window.m_event);
		ImGui_ImplSDL2_ProcessEvent(&m_window.m_event);

		switch (m_window.m_event.type)
		{
		case SDL_QUIT:
			m_window.Close();
			m_running = false;
			break;

		default:
			m_scene.ProcessEntities();

			// ImGui
			ImGui_ImplSDL2_NewFrame(m_window);
			ImGui_ImplSDLRenderer_NewFrame();
			ImGui::NewFrame();

			ImGui::ShowDemoWindow((bool*)_DEBUG);

			m_hierarchy.OnImGuiRender();

			ImGui::Render();
			ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

			SDL_RenderPresent(m_window.m_renderer);
			break;
		}
		 
		auto delta = signed(1000 / m_framerate - std::chrono::duration_cast<std::chrono::milliseconds>(clock_highp::now() - begin).count());

		if (0 <= delta)
			SDL_Delay(delta);
	}
}