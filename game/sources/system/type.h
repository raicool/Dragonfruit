#pragma once
#include <cstdint>

namespace DragonFruit
{
	// Vectors
	template<typename T>
	struct Vector2  { T x, y; };

	template<typename T>
	struct Vector3  { T x, y, z; };

	template<typename T>
	struct Vector4  { T x, y, z, w; };

	// Color vectors
	struct Rgb      { uint8_t r, g, b; };
	struct Rgba     { uint8_t r, g, b, a; };
}