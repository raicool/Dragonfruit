#pragma once

#include "system/resource.h"
#include "system/type.h"

#include "system/debug.h"

namespace Dragonfruit
{
	class Quad
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

		void SetSize(Vector2<float> newsize) 
		{ 
			m_rect.w = newsize.x; 
			m_rect.h = newsize.y;
		}

		void SetPosition(Vector2<float> newpos)
		{
			m_rect.x = newpos.x;
			m_rect.y = newpos.y;
		}
		
		void SetTexture(const char* texture)
		{
			m_texture = Resource::Get().GetTexture(texture);

			if (texture == nullptr)
			{
				DF_LOG_ERROR("Texture could not be found!");
			}
			else
			{
				m_texturename = const_cast<char*>(texture);
			}
		}

		operator SDL_FRect* const () { return &m_rect; }
	};
}