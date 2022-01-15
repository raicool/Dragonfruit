#include "pch.h"

namespace DragonFruit
{
	void Application::Start()
	{
		m_Running = true;
		// Load Textures
		m_Resources.LoadTexture("grid", "resources/texture/grid.png");
		m_Resources.LoadTexture("grass", "resources/texture/grass.png");
		m_Resources.LoadTexture("placeholder", "resources/texture/placehold.png");
		m_Resources.LoadTexture("fireicon", "resources/texture/fire.png");
		m_Resources.LoadTexture("noise", "resources/texture/noise.png");

		m_Player = new Entity(m_Resources.GetTexture("grid"), Vector2 { 0, 0 }, Vector2 { 32, 32 });

		m_EntityManager.AddEntity(m_Player);
	}

	void Application::Update()
	{
		Window::Get().Update(m_Running);
	}

	Application::Application()
		: m_Resources(Resources::Get()),
		  m_EntityManager(EntityManager::Get())
	{
		this->Start();
	}

}