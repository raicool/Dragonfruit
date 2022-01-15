#include "pch.h"

namespace DragonFruit
{
    void Texture::Create(const char* _dir, const char* _tfilter)
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, _tfilter);

        m_Surface = IMG_Load(_dir);
        m_Texture = SDL_CreateTextureFromSurface(Window::Get().GetRenderer(), m_Surface);

        TextureCount++;
        m_Id = TextureCount; // New Texture ID

        if (!m_Surface) { DF_LOG_ERROR("Texture with id " << m_Id << " ... " << SDL_GetError()); TextureCount--; }
        else           { DF_LOG_DEBUG("Texture with id " << m_Id << " created."); }

        SDL_FreeSurface(m_Surface);
    }

    Texture::~Texture()
    {
        // Cleanup
        SDL_DestroyTexture(this->m_Texture);

        DF_LOG_DEBUG("Texture with id " << this->m_Id << " destroyed.");

        TextureCount--;
    }

    Texture::Texture()
    {
    }
}