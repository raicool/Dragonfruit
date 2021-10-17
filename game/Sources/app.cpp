#include "pch.h"
#include "app.h"
#include "Dragonfruit/entity.h"

namespace DragonFruit
{
	void Application::OnCreate()
	{
		DF_GLCALL(glDrawArrays(1, 1, 1));

		m_OrthoCamera.Create(-1.0f, 1.0f, -1.0f, 1.0f);
		m_Shader.LoadShaders("./Resources/Shader/vertex.glsl", "./Resources/Shader/fragment.glsl");

		// Enable wireframe display GL_LINE
		DF_DEBUGLINE(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));

		// flags we will need to enable
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glDepthFunc(GL_LESS);

		m_Window.SetClearColor(0, 0, 0.5);
	}

	void Application::OnUpdate()
	{	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		// ImGui content
		{
			ImGui::NewFrame();
			ImGui::Begin("Debug");
			ImGui::Text("%.3f FPS  (%.3f ms/frame)", m_ImGuiIO.Framerate, 1000 / m_ImGuiIO.Framerate);
			ImGui::End();
		}

		Render::Draw(m_Window);
		m_Window.Update();
	}

	void Application::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
	}

	Application::Application()
		: m_ImGuiIO(ImGui::GetIO())
	{
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");
		this->OnCreate();
	}

	Application::~Application()
	{
		this->Shutdown();
	}
}