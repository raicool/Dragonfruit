#pragma once

#include <glew.h>

namespace DragonFruit
{
	struct Vertex
	{
		float Position[3];
		float TextureCoords[2];
	};

	class VertexBuffer
	{
	public:
		void Bind() const;
		void Unbind() const;
		void Set(std::vector<Vertex>& data);

		const uint32_t& GetSize() { return m_Size; }

		VertexBuffer(std::vector<Vertex>& data);
		VertexBuffer();
		~VertexBuffer();

	private:
		uint32_t m_VBO;
		uint32_t m_Size;
	};

	class IndexBuffer
	{
	public:
		void Bind() const;
		void Unbind() const;
		void Set(std::vector<uint32_t>& data);

		const uint32_t GetCount() { return m_Count; }

		IndexBuffer(std::vector<uint32_t>& index);
		IndexBuffer();
		~IndexBuffer();

	private:
		uint32_t m_IBO;
		uint32_t m_Count;
	};
}