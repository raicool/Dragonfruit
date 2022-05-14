#include "pch.h"

#include "window.h"
#include "app.h"

#include "system/entity.h"

#include "system/debug.h"

namespace Dragonfruit
{

	void Window::SetClearColor(Rgb _color)
	{
		SDL_SetRenderDrawColor(m_renderer, _color.r, _color.g, _color.b, 255);
	}

	void Window::PassQuadToRenderer(QuadComponent& quad)
	{
		if (SDL_RenderCopyExF(m_renderer, quad.GetTexture(), NULL, quad, quad.GetAngle(), NULL, SDL_FLIP_NONE) == -1)
			DF_LOG_ERROR("Problem rendering quad. loc : {}", (void*)quad);
	}

	Window::Window()
	{
		m_window = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WinWidth, WinHeight, SDL_WINDOW_RESIZABLE);
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (!m_window) { DF_LOG_ERROR("SDL Window could not be created {}", SDL_GetError()); }
		else           { DF_LOG_INFO("SDL Window initialized"); }

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
		DF_LOG_INFO("SDL Window destroyed");
	}
}