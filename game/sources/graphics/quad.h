#pragma once

namespace DragonFruit
{
	class Quad
	{
	private:
		SDL_FRect m_Rect;
		Texture& m_Texture;
		double m_Angle;

	public:
		void SetTexture(Texture& _texture) { m_Texture = _texture; }
		Texture& GetTexture() { return m_Texture; }

		SDL_FRect& GetRect() { return m_Rect; }
		double& GetAngle() { return m_Angle; }

		operator SDL_FRect* const () { return &m_Rect; }
		
		Quad(Vector2, Vector2);
		~Quad();
	};
}