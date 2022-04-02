#pragma once

#define MAX_INSTANCED_TEXTURES 256

namespace Dragonfruit
{
	class Resource
	{
	public:
		/* 
		* @brief Load a specified texture into the texture map
		* @param identifier: map key
		* @param directory: directory of the texture
		* @param filter: filter mode  
		*	0 = nearest
		*	1 = linear
		*	2 = best / anisotropic (D3D Only)
		*/
		void LoadTexture(const char* identifier, const char* directory, const char* filter = "0");
		SDL_Texture* GetTexture(std::string_view);
		
		static Resource& Get();

	private:
		using TextureMap = std::unordered_map<std::string_view, SDL_Texture*>;

		// Unordered map of all loaded textures (key being identifier)
		TextureMap m_textures;

		uint32_t m_texturecount;
	};
}