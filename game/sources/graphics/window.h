#pragma once

constexpr const char* Title = "SDL";
constexpr int WinWidth = 1326;
constexpr int WinHeight = 720;
constexpr bool VSync = true;

namespace DragonFruit
{
	class Window
	{
	private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Render;
		SDL_Event m_Event;

		uint32_t m_Framerate;
		uint64_t m_Framecount;

	public:
		static Window& Get();

		void Update(bool&);
		void Close();

		void SetClearColor(Rgb&);
		void SetFramerate(uint32_t);

		void PassQuadToRenderer(Quad&);

		uint64_t& GetFramecount() { return m_Framecount; }
		SDL_Renderer* GetRenderer() { return m_Render; }

		Window();
		~Window();
	};
}