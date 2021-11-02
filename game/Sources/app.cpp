#include "pch.h"
#include "app.h"
#include "Dragonfruit/entity.h"

namespace DragonFruit
{
	void Application::OnCreate()
	{
		m_OrthoCamera.Create(-1.0f, 1.0f, -1.0f, 1.0f);
		m_Shader.LoadShaders("./Resources/Shader/vertex.glsl", "./Resources/Shader/fragment.glsl");

		m_OrthoCamera.SetPosition({ -1.0, -1.0, -1.0 });
		m_Shader.SendUniformMat4("u_VPMatrix", m_OrthoCamera.VPMatrix());

		//DF_DEBUGLINE(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
		DF_GLCALL(glEnable(GL_BLEND));
		DF_GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		DF_GLCALL(glEnable(GL_DEPTH_TEST));
		DF_GLCALL(glEnable(GL_CULL_FACE));
		DF_GLCALL(glDepthFunc(GL_LESS));

		m_Window.SetClearColor(0, 0, 0.5);

		DF_LOG_WARN("this is a warning!!");
		DF_LOG_ERROR("this is a error!!");
		DF_LOG_DEBUG("this is a debug!!");
		DF_LOG_FATAL("this is a fatal!!");

		DF_GLCALL(glUseProgram(m_Shader));
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
			ImGui::NewLine();
			ImGui::Text("%.3f", m_OrthoCamera.Position().x);
			ImGui::Text("%.3f", m_OrthoCamera.Position().y);
			ImGui::Text("%.3f", m_OrthoCamera.Position().z);
			ImGui::NewLine();
			ImGui::Text("%.3f", m_OrthoCamera.RotationDeg());
			ImGui::End();
		}

		Render::Draw(m_Window);
		m_Window.Update();
	}

	void Application::Shutdown()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		glfwTerminate();
	}

	Application::Application()
		: m_ImGuiIO(ImGui::GetIO()), m_Texture("./Resources/Texture/atlas.png"), m_Player(m_Texture)
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