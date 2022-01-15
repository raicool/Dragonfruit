#pragma once
#include <cstdint>

namespace DragonFruit
{
	// Float vectors
	struct Vector2  { float x, y; };
	struct Vector3  { float x, y, z; };

	// Double vectors
	struct Vector2d { double x, y; };
	struct Vector3d { double x, y, z; };

	// Char vectors
	struct Vector2c { uint8_t x, y; };
	struct Vector3c { uint8_t x, y, z; };

	// Short vectors
	struct Vector2s { uint16_t x, y; };
	struct Vector3s { uint16_t x, y, z; };

	// Int vectors
	struct Vector2i { uint32_t x, y; };
	struct Vector3i { uint32_t x, y, z; };
	
	// Color vectors
	struct Rgb      { uint8_t r, g, b; };
	struct Rgba     { uint8_t r, g, b, a; };
}