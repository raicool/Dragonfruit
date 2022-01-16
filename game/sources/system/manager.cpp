#include <pch.h>

namespace DragonFruit
{
	void Resources::LoadTexture(const char* _identifier, const char* _directory, const char* _tfilter)
	{
		if (m_TextureCount <= MAX_INSTANCED_TEXTURES)
		{
			m_Textures[_identifier] = Texture::Create(_directory, _tfilter);

			if (m_Textures[_identifier] != nullptr)
			{
				m_TextureCount++;
				DF_LOG_DEBUG("Texture " << m_TextureCount << " Created");
			}
		}
		else
		{
			DF_LOG_ERROR("Too many textures loaded!");
		}
	}

	SDL_Texture* Resources::GetTexture(const char* _identifier)
	{
		return m_Textures[_identifier];
	}

	Resources& Resources::Get()
	{
		static Resources _instance;
		return _instance;
	}
}