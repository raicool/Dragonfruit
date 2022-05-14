#pragma once

#include <SDL.h>

#include "system/type.h"
#include "quad.h"

namespace Dragonfruit
{
	constexpr const char* Title = "SDL";
	constexpr int32_t WinWidth = 1326;
	constexpr int32_t WinHeight = 720;
	constexpr bool VSync = true;

	class Window
	{
	public:
		void Close();
		void SetClearColor(Rgb);
		void PassQuadToRenderer(QuadComponent&);

		SDL_Renderer* GetRenderer() { return m_renderer; }

		operator SDL_Window* const () { return m_window; }

		Window();
		~Window();

	private:
		friend class Application;

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Event m_event;
	};
}