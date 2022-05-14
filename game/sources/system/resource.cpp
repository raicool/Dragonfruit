#include <pch.h>

#include "resource.h"
#include "app.h"

#include "debug.h"

namespace Dragonfruit
{
	void Resource::LoadTexture(const char* identifier, const char* directory, const char* tfilter)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

		SDL_Surface* surface = IMG_Load(directory);

		if (!surface) 
		{ 
			DF_LOG_ERROR("Error creating texture {} : {}", identifier, SDL_GetError());
			return;
		}
			
		Textures[identifier] = SDL_CreateTextureFromSurface(Application::Get()->GetWindow().GetRenderer(), surface);
		DF_LOG_TRACE("Texture {} created at address {}", identifier, (void*)Textures[identifier]);
		TextureCount++;

		SDL_FreeSurface(surface);
	}

	SDL_Texture* Resource::GetTexture(std::string_view identifier)
	{
//		DF_LOG_INFO("{} Location : {}", identifier, (void*)m_textures[identifier]);
		return Textures[identifier];
	}
}