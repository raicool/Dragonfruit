#include "pch.h"

#include "texture.h"

#define TEX_RGB 3
#define TEX_RGBA 4

namespace DragonFruit
{
	Texture::Texture(const char* path)
		: m_TextureDataBuffer(nullptr)
	{
		stbi_set_flip_vertically_on_load(true);
		m_TextureDataBuffer = stbi_load(path, &m_Width, &m_Height, &m_bpp, TEX_RGBA);

		DF_GLCALL(glGenTextures(1, &m_RenderID));
		DF_GLCALL(glBindTexture(GL_TEXTURE_2D, m_RenderID));

		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER));
		DF_GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER));

		DF_GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_TextureDataBuffer));
		this->Unbind();

		// free image buffer
		if (m_TextureDataBuffer)
			stbi_image_free(m_TextureDataBuffer);

		this->Bind();
	}

	Texture::~Texture()
	{
		DF_GLCALL(glDeleteTextures(1, &m_RenderID));
	}

	void Texture::Bind(unsigned int slot /*= 0*/) const
	{
		DF_GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
		DF_GLCALL(glBindTexture(GL_TEXTURE_2D, m_RenderID));
	}

	void Texture::Unbind() const
	{
		DF_GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
	}
}
