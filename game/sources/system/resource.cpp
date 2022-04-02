#include <pch.h>

#include "resource.h"
#include "app.h"

#include "debug.h"

namespace Dragonfruit
{
	void Resource::LoadTexture(const char* identifier, const char* directory, const char* tfilter)
	{
		if (m_texturecount <= MAX_INSTANCED_TEXTURES)
		{
			SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, tfilter);

			SDL_Surface* _surface = IMG_Load(directory);

			if (!_surface) 
			{ 
				DF_LOG_ERROR("Error creating texture {} : {}", identifier, SDL_GetError()); 
			}
			else
			{
				m_textures[identifier] = SDL_CreateTextureFromSurface(Application::Get()->GetWindow().GetRenderer(), _surface);
				DF_LOG_TRACE("Texture {} created at address {}", identifier, (void*)m_textures[identifier]);
				m_texturecount++;
			}
			SDL_FreeSurface(_surface);
		}
		else
		{
			DF_LOG_ERROR("Too many textures loaded!");
		}
	}

	SDL_Texture* Resource::GetTexture(std::string_view identifier)
	{
		DF_LOG_INFO("{} Location : {}", identifier, (void*)m_textures[identifier]);
		return m_textures[identifier];
	}

	Resource& Resource::Get()
	{
		static Resource instance;
		return instance;
	}
}