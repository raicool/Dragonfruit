#pragma once

// mostly from https://www.youtube.com/watch?v=n4k7ANAFsIQ
namespace DragonFruit
{
	struct Texture
	{
	public:
		Texture(const char* path);
		~Texture();

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;

		int GetWidth()  const { return m_Width;  }
		int GetHeight() const { return m_Height; }

	private:
		uint32_t m_RenderID;
		uint8_t* m_TextureDataBuffer;
		int32_t m_Width, m_Height, m_bpp;
	};
}