#include <pch.h>

namespace DragonFruit
{
	void Resources::LoadTexture(const char* _identifier, const char* _directory, const char* _tfilter)
	{
		if (m_TextureCount <= MAX_INSTANCED_TEXTURES)
		{
			m_Textures[_identifier] = new Texture();
			m_Textures[_identifier]->Create(_directory, _tfilter);
			m_TextureCount++;
		}
		else
		{
			DF_LOG_ERROR("Too many textures loaded!");
		}
	}

	Texture* Resources::GetTexture(const char* _directory)
	{
		return m_Textures[_directory];
	}

	Resources& Resources::Get()
	{
		static Resources _instance;
		return _instance;
	}
}