#pragma once

namespace DragonFruit
{
	class Quad
	{
	private:
		SDL_FRect m_Rect;
		SDL_Texture* m_Texture;
		double m_Angle{ 0.0f };

	public:
		void SetTexture(SDL_Texture* _texture) { m_Texture = _texture; }
		SDL_Texture* GetTexture() { return m_Texture; }

		SDL_FRect& GetRect() { return m_Rect; }
		double& GetAngle() { return m_Angle; }

		void SetSize(Vector2<float> _newsize) 
		{ 
			m_Rect.w = _newsize.x; 
			m_Rect.h = _newsize.y;
		};

		operator SDL_FRect* const () { return &m_Rect; }
		
		Quad();
		~Quad();
	};
}