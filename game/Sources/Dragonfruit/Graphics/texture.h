#pragma once

// mostly from https://www.youtube.com/watch?v=n4k7ANAFsIQ
namespace DragonFruit
{
	struct Texture
	{
	private:
		GLuint m_renderID;
		unsigned char* m_texdatabuf;
		int m_width, m_height, m_bpp;
		unsigned char ID;

	public:
		Texture(const char* path);
		~Texture();

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;

		int GetWidth()  const { return m_width;  }
		int GetHeight() const { return m_height; }
	};
}