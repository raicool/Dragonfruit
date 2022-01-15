#include "pch.h"

int main()
{
	using namespace DragonFruit;

	SDL_Init(SDL_INIT_EVERYTHING);
	Application App;

	while(true)
	{
		App.Update();
	}

	return 0;
}