#pragma once

#include "buffer.h"

namespace DragonFruit
{
	class VertexArray
	{
	public:
		void Bind() const;
		void Unbind() const;
		void AddVertexBuffer(VertexBuffer);
		void AddIndexBuffer(IndexBuffer);

		VertexArray();
		~VertexArray();

	private:
		friend class Render;

		GLuint m_VAO;

		std::vector<VertexBuffer> m_VertexBuffer;
		IndexBuffer m_IndexBuffer;

		uint32_t m_VertexOffset;
		uint32_t m_VertexIndex;
	};
}