#include "pch.h"

#include "window.h"
#include "app.h"

#include "system/entity.h"

#include "system/debug.h"

namespace Dragonfruit
{
	void Window::Update(bool& running)
	{
		this->SetClearColor(Rgb{ 32, 64, 128 });
		SDL_RenderClear(m_renderer);
		SDL_PollEvent(&m_event);
		ImGui_ImplSDL2_ProcessEvent(&m_event);

		switch (m_event.type)
		{
			case SDL_QUIT: 
				this->Close();
				running = false;
				break;

			default:
				ImGui_ImplSDL2_NewFrame(m_window);
				ImGui_ImplSDLRenderer_NewFrame();
				ImGui::NewFrame();

				ImGui::ShowDemoWindow((bool*)true);
				
				Application::Get()->m_hierarchy.OnImGuiRender();

				ImGui::Render();
				ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
		
				SDL_RenderPresent(m_renderer);
				break;
		}

		//SDL_Delay(1000 / m_Framerate);
	}

	void Window::SetClearColor(Rgb& _color)
	{
		SDL_SetRenderDrawColor(m_renderer, _color.r, _color.g, _color.b, 255);
	}

	void Window::PassQuadToRenderer(Quad& quad)
	{
		SDL_RenderCopyExF(m_renderer, quad.GetTexture(), NULL, quad, quad.GetAngle(), NULL, SDL_FLIP_NONE);
	}

	Window::Window()
	{
		m_window = SDL_CreateWindow(m_windowspecs.Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowspecs.WinWidth, m_windowspecs.WinHeight, SDL_WINDOW_RESIZABLE);
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (m_window == NULL) { DF_LOG_ERROR("SDL Window could not be created. {}\n", SDL_GetError()); }
		else                  { DF_LOG_INFO("SDL Window initialized"); }

		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplSDL2_InitForSDLRenderer(m_window, m_renderer);
		ImGui_ImplSDLRenderer_Init(m_renderer);
	}

	void Window::Close()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	Window::~Window()
	{
		DF_LOG_INFO("SDL Window destroyed.")
	}
}