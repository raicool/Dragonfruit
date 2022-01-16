#pragma once

namespace DragonFruit
{
	static uint32_t TextureCount;

	class Texture
	{
	public:
		static SDL_Texture* Create(const char*, const char*);
	};
}