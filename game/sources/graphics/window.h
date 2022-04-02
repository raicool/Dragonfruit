#pragma once

#include <SDL.h>

#include "system/type.h"
#include "quad.h"

namespace Dragonfruit
{
	struct WindowSpecification
	{
		const char* Title = "SDL";
		int32_t WinWidth  = 1326;
		int32_t WinHeight = 720;
		bool Vsync        = true;
	};

	class Window
	{
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Event m_event;

		WindowSpecification m_windowspecs;

	public:
		void Update(bool&);
		void Close();

		void SetClearColor(Rgb&);

		void PassQuadToRenderer(Quad&);

		SDL_Renderer* GetRenderer() { return m_renderer; }

		Window();
		~Window();
	};
}