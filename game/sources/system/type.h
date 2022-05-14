#pragma once
#include <cstdint>

namespace Dragonfruit
{
	// Vectors
	template<typename T>
	struct Vector2  
	{
		T x, y; 
		Vector2 operator* (float _fval)
		{
			return Vector2
			{
				this->x *= _fval,
				this->y *= _fval
			};
		}
	};

	template<typename T>
	struct Vector3  
	{ 
		T x, y, z; 
		Vector3 operator* (float _fval)
		{
			return Vector3
			{
				this->x *= _fval,
				this->y *= _fval,
				this->z *= _fval
			};
		}
	};

	template<typename T>
	struct Vector4  
	{ 
		T x, y, z, w; 
		Vector4 operator* (float _fval)
		{
			return Vector4
			{
				this->x *= _fval,
				this->y *= _fval,
				this->z *= _fval,
				this->w *= _fval
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