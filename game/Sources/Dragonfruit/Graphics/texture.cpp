#include "pch.h"

#include "texture.h"

#define TEX_RGB 3
#define TEX_RGBA 4

namespace DragonFruit
{
	Texture::Texture(const char* path)
		: m_texdatabuf(nullptr)
	{
		stbi_set_flip_vertically_on_load(true);
		m_texdatabuf = stbi_load(path, &m_width, &m_height, &m_bpp, TEX_RGBA);

		DF_GLCALL(glGenTextures(1, &m_renderID));
		DF_GLCALL(glBindTexture(GL_TEXTURE_2D, m_renderID));

		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER));
		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER));

		DF_GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_texdatabuf));
		this->Unbind();

		// free image buffer
		if (m_texdatabuf)
			stbi_image_free(m_texdatabuf);

		this->Bind();
	}

	Texture::~Texture()
	{
		DF_GLCALL(glDeleteTextures(1, &m_renderID));
	}

	void Texture::Bind(unsigned int slot /*= 0*/) const
	{
		DF_GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
		DF_GLCALL(glBindTexture(GL_TEXTURE_2D, m_renderID));
	}

	void Texture::Unbind() const
	{
		DF_GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
	}
}
