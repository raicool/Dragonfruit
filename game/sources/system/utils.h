#pragma once

#include "type.h"
#include "resource.h"

#include "debug.h"

namespace Dragonfruit
{
	namespace Utils
	{
		template<typename T>
		Vector2<T> GetSizeOfTexture(std::string identifier)
		{
			int32_t _checkw, _checkh;
			SDL_QueryTexture(Resource::GetTexture(identifier), NULL, NULL, &_checkw, &_checkh);
//			DF_LOG_TRACE("Texture dimensions: {}, {}", _checkw, _checkh);

			return Vector2<T>{ (T)_checkw, (T)_checkh };
		}

		template<typename T>
		using Reference = std::shared_ptr<T>;
	}
}