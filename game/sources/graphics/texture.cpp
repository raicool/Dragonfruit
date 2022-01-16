#include "pch.h"

namespace DragonFruit
{
    SDL_Texture* Texture::Create(const char* _dir, const char* _tfilter)
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, _tfilter);

        SDL_Surface* _surface = IMG_Load(_dir);
        SDL_Texture* _texture = SDL_CreateTextureFromSurface(Window::Get().GetRenderer(), _surface);

        if (!_surface) { return nullptr; }
        else           { return _texture; }

        SDL_FreeSurface(_surface);
        SDL_DestroyTexture(_texture);
    }
}