#pragma once
#include <cstdint>

namespace Dragonfruit
{
	// Vectors
	template<typename T>
	struct Vector2  
	{
		T x, y; 
		Vector2 operator* (float _other)
		{
			return Vector2
			{
				this->x *= _other,
				this->y *= _other
			};
		}
	};

	template<typename T>
	struct Vector3  
	{ 
		T x, y, z; 
		Vector3 operator* (float _other)
		{
			return Vector3
			{
				this->x *= _other,
				this->y *= _other,
				this->z *= _other
			};
		}
	};

	template<typename T>
	struct Vector4  
	{ 
		T x, y, z, w; 
		Vector4 operator* (float _other)
		{
			return Vector4
			{
				this->x *= _other,
				this->y *= _other,
				this->z *= _other,
				this->w *= _other
			};
		}
	};


	// Matrix
	template <typename T, uint32_t Size>
	struct Matrix
	{
		T m_Data[Size][Size];

		T* begin() const { return *m_Data; }
		T* end() const { return *m_Data + ((Size * 2) * sizeof(T)); }
	};

	// Color vectors
	struct Rgb      { uint8_t r, g, b; };
	struct Rgba     { uint8_t r, g, b, a; };
}