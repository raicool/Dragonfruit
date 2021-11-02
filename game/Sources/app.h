#pragma once

#include "dragonfruit/graphics/window.h"
#include "dragonfruit/graphics/render.h"
#include "dragonfruit/graphics/shader.h"
#include "dragonfruit/graphics/camera.h"
#include "dragonfruit/entity.h"

namespace DragonFruit
{
	class Application
	{
	public:
		void OnCreate();
		void OnUpdate();

		void Shutdown();

		GLFWwindow* GetWindow() const { return m_Window; }

		Application();
		~Application();

	private:
		Window m_Window;
		Shader m_Shader;
		OrthographicCamera m_OrthoCamera;
		Player m_Player;
		Texture m_Texture;

		ImGuiIO& m_ImGuiIO;
	};
}