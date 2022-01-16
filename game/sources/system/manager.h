#pragma once

#define MAX_INSTANCED_TEXTURES 256

namespace DragonFruit
{
	using TextureMap = std::unordered_map<std::string, SDL_Texture*>;

	class Resources
	{
	private:
		TextureMap m_Textures;
		uint32_t m_TextureCount;

	public:
		void LoadTexture(const char*, const char*, const char* = "0");
		SDL_Texture* GetTexture(std::string);

		static Resources& Get();
	};
}