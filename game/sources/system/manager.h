#pragma once

#define MAX_INSTANCED_TEXTURES 256

namespace DragonFruit
{
	using TextureMap = std::unordered_map<const char*, Texture*>;

	class Resources
	{
	private:
		TextureMap m_Textures;
		uint32_t m_TextureCount;

	public:
		void LoadTexture(const char*, const char*, const char* = "0");
		Texture* GetTexture(const char*);

		static Resources& Get();
	};
}