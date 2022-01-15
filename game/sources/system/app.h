#pragma once
#include "entity.h"

namespace DragonFruit
{
	class Application
	{
		bool m_Running = false;
		Entity* m_Player;

		EntityManager& m_EntityManager;
		Resources& m_Resources;

	public:
		void Start();
		void Update();

		Application();

		bool IsRunning() const { return m_Running; }
	};
}