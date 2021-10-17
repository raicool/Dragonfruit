#pragma once

#include "dragonfruit/graphics/window.h"
#include "dragonfruit/graphics/render.h"
#include "dragonfruit/graphics/shader.h"
#include "dragonfruit/graphics/camera.h"

namespace DragonFruit
{
	class Application
	{
	public:
		void OnCreate();
		void OnUpdate();

		// this doesnt work
		void Shutdown();

		GLFWwindow* GetWindow() const { return m_Window; }

		Application();
		~Application();

	private:
		Window m_Window;
		Shader m_Shader;
		OrthographicCamera m_OrthoCamera;

		ImGuiIO& m_ImGuiIO;
	};
}