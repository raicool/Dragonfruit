#include "pch.h"

namespace DragonFruit
{
	void Application::Start()
	{
		m_Running = true;
		// Load Textures
		auto& _ResourcesInstance = Resources::Get();
		_ResourcesInstance.LoadTexture("grid", "resources/texture/grid.png");
		_ResourcesInstance.LoadTexture("grass", "resources/texture/grass.png");
		_ResourcesInstance.LoadTexture("placeholder", "resources/texture/placehold.png");
		_ResourcesInstance.LoadTexture("fireicon", "resources/texture/fire.png");
		_ResourcesInstance.LoadTexture("noise", "resources/texture/noise.png");

		m_Player = new Player(_ResourcesInstance.GetTexture("grid"), Vector2 { 0, 0 }, Vector2 { 32, 32 });

		EntityManager::Get().AddEntity(m_Player);
	}

	void Application::Update()
	{
		m_Player->HandleInputs();

		Window::Get().Update(m_Running);
	}

	Application::Application()
	{
		this->Start();
	}

}