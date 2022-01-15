#pragma once
#include "entity.h"

namespace DragonFruit
{
	class Application
	{
		bool m_Running = false;
		Player* m_Player;
	public:
		void Start();
		void Update();

		Application();

		bool IsRunning() const { return m_Running; }
	};
}