#pragma once

namespace Dragonfruit
{
	namespace Resource
	{
		using TextureMap = std::unordered_map<std::string_view, SDL_Texture*>;

		/* 
		* @brief Load a specified texture into the texture map
		* @param identifier: map key
		* @param directory: directory of the texture
		* @param filter: filter mode  
		*	0 = nearest
		*	1 = linear
		*	2 = best / anisotropic (Direct3D only)
		*/
		void LoadTexture(const char* identifier, const char* directory, const char* filter = "0");
		SDL_Texture* GetTexture(std::string_view);

		// Unordered map of all loaded textures (key being identifier)
		inline TextureMap Textures;
		inline uint32_t TextureCount;
	};
}