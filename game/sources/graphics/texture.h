#pragma once

namespace DragonFruit
{
	static uint32_t TextureCount;

	class Texture
	{
	private:
		SDL_Surface* m_Surface;
		SDL_Texture* m_Texture;

		uint32_t m_Id;

	public:
		void Create(const char*, const char*);

		Texture();
		~Texture();

		operator SDL_Texture* () { return m_Texture; }
//		Texture operator= (Texture& _new)
//		{
//			m_Texture = _new;
//			return *this;
//		}
	};
}