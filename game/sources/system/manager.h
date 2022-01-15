#pragma once

#define MAX_INSTANCED_TEXTURES 256

namespace DragonFruit
{
	using TextureMap = std::unordered_map<const char*, Texture*>;

	class Resources
	{
	private:
		static TextureMap m_Textures;
		static uint32_t m_TextureCount;

	public:
		static void LoadTexture(const char*, const char*, const char* = "0");
		static Texture& GetTexture(const char*);
	};
}