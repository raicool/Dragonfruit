#pragma once

#include <glew.h>
#include <vector>

namespace DragonFruit
{
	enum class BufferTypeSize
	{
		Char = 1,
		Short = 2,
		Int = 4,
		Float = 4,
		Float2 = 8,
		Float3 = 12,
		Long = 8,
		Double = 8,
		Double2 = 16,
		Double3 = 24
	};

	class VertexBuffer
	{
	public:
		void Bind();
		void Unbind();

	private:
		static GLuint m_VBO;

	};

	class VertexBufferLayout
	{
	public:
		struct Element
		{
			BufferTypeSize Type;
			const char* Identifier;
		};

		std::vector<Element> VertexElements;

		void SetLayout(Element& _element) 
		{ 
			VertexElements.push_back({ _element.Type, _element.Identifier });
		}
	};
}