#include <pch.h>

namespace DragonFruit
{
	void Resources::LoadTexture(const char* _identifier, const char* _directory, const char* _tfilter)
	{
		if (m_TextureCount <= MAX_INSTANCED_TEXTURES)
		{
			SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, _tfilter);

			SDL_Surface* _surface = IMG_Load(_directory);

			if (!_surface) 
			{ 
				DF_LOG_ERROR("Error creating texture " << _identifier << " : " << SDL_GetError()); 
			}
			else
			{
				m_Textures[_identifier] = SDL_CreateTextureFromSurface(Window::Get().GetRenderer(), _surface);

				if (m_Textures[_identifier])
				{
					m_TextureCount++;
					DF_LOG_DEBUG("Texture " << _identifier << " Created at " << m_Textures[_identifier]);
				}
			}
			SDL_FreeSurface(_surface);
		}
		else
		{
			DF_LOG_ERROR("Too many textures loaded!");
		}
	}

	SDL_Texture* Resources::GetTexture(std::string _identifier)
	{
		DF_LOG_DEBUG("Loc : " << m_Textures[_identifier]);
		return m_Textures[_identifier];
	}

	Resources& Resources::Get()
	{
		static Resources _instance;
		return _instance;
	}
}