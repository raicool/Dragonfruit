#include "pch.h"

namespace DragonFruit
{
	void Window::Update(bool& running)
	{
		SetClearColor(32, 64, 128);
		SDL_RenderClear(m_Render);
		
		SDL_PollEvent(&m_Event);

		switch (m_Event.type)
		{
			case SDL_QUIT: 
				SDLClose();
				running = false;
				break;

			default:
				EntityManager::Get().Process(*this);
				SDL_RenderPresent(m_Render);
				m_Framecount++;
				break;
		}

		SDL_Delay(1000 / m_Framerate);
	}

	void Window::SetClearColor(uint8_t r, uint8_t g, uint8_t b)
	{
		SDL_SetRenderDrawColor(m_Render, r, g, b, 255);
	}

	void Window::SetFramerate(uint32_t framerate)
	{
		m_Framerate = framerate;
	}

	void Window::PassQuadToRenderer(Quad& quad)
	{
		SDL_RenderCopyExF(m_Render, quad.GetTexture(), NULL, quad, quad.GetAngle(), NULL, SDL_FLIP_NONE);
	}

	Window::Window()
	{
		m_Window = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WinWidth, WinHeight, SDL_WINDOW_RESIZABLE);
		m_Render = SDL_CreateRenderer(m_Window, -1, 0);
		m_Framerate = 60;

		//SDL_GL_SetSwapInterval(VSync);

		if (m_Window == NULL) { DF_LOG_ERROR("SDL Window could not be created.\n" << SDL_GetError()); }
		else { DF_LOG_INFO("SDL Window initialized."); }
	}

	void Window::SDLClose()
	{
		SDL_DestroyRenderer(m_Render);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	Window::~Window()
	{
		DF_LOG_INFO("SDL Window destroyed.")
	}

	Window& Window::Get()
	{
		static Window instance;
		return instance;
	}
}