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
		inline static SDL_Window* m_Window;
		inline static SDL_Renderer* m_Render;
		inline static SDL_Event m_Event;

		inline static uint32_t m_Framerate;
		inline static uint64_t m_Framecount;

	public:
		static void Update();
		static void Close();

		static void SetClearColor(uint8_t, uint8_t, uint8_t);
		static void SetFramerate(uint32_t);

		static void PassQuadToRenderer(Quad&);

		static uint64_t& GetFramecount() { return m_Framecount; }
		static SDL_Renderer* GetRenderer() { return m_Render; }

		Window();
		~Window();
	};
}