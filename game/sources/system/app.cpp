#include "pch.h"

namespace DragonFruit
{
	void Application::Start()
	{
		// Load Textures
		Resources::LoadTexture("grid", "resources/texture/grid.png");
		Resources::LoadTexture("grass", "resources/texture/grass.png");
		Resources::LoadTexture("placeholder", "resources/texture/placehold.png");
		Resources::LoadTexture("fireicon", "resources/texture/fire.png");
		Resources::LoadTexture("noise", "resources/texture/noise.png");

		EntityManager::CreatePlayer(Resources::GetTexture("grid"), { 0, 0 });
	}

	void Application::Update()
	{
		EntityManager::GetEntityTable()[0]->HandleInputs();

		Window::Update();
	}

	Application::Application()
	{
		this->Start();
	}

}