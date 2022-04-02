#include "pch.h"

#include "app.h"

int main()
{
	using namespace Dragonfruit;

	SDL_Init(SDL_INIT_EVERYTHING);

	Log::Init();
	Application App;

	while (App.IsRunning())
	{
		App.Update();
	}

	return 0;
}