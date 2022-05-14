#pragma once

#include "system/resource.h"
#include "system/type.h"

#include "system/debug.h"

namespace Dragonfruit
{
	class QuadComponent
	{
	private:
		SDL_FRect m_rect;
		SDL_Texture* m_texture;
		double m_angle{ 0.0f };
		char* m_texturename;

	public:
		SDL_Texture* GetTexture() { return m_texture; }
		const char* GetTextureName() { return m_texturename; }
		SDL_FRect& GetRect() { return m_rect; }
		double& GetAngle() { return m_angle; }

		void SetSize(Vector2<float> newsize);
		void SetPosition(Vector2<float> newpos);
		void SetTexture(const char* texture);

		operator SDL_FRect* const () { return &m_rect; }
	};
}