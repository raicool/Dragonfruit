#include "pch.h"

#include "buffer.h"

namespace DragonFruit
{
	void VertexBuffer::Bind() const
	{
        DF_GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
	}

	void VertexBuffer::Unbind() const
	{
		DF_GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void VertexBuffer::Set(std::vector<Vertex>& vertex)
	{
		m_Size = vertex.size() * sizeof(float);

		this->Bind();
		DF_GLCALL(glBufferSubData(GL_ARRAY_BUFFER, 0, m_Size, vertex.data()));
	}

    VertexBuffer::VertexBuffer(std::vector<Vertex>& data)
    {
        DF_GLCALL(glGenBuffers(1, &m_VBO));
		this->Set(data);
    }

	VertexBuffer::VertexBuffer()
	{
		DF_GLCALL(glGenBuffers(1, &m_VBO));
	}

	VertexBuffer::~VertexBuffer()
	{
		DF_GLCALL(glDeleteBuffers(1, &m_VBO));
	}

	void IndexBuffer::Bind() const
	{
		DF_GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO));
	}

	void IndexBuffer::Unbind() const
	{
		DF_GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	void IndexBuffer::Set(std::vector<unsigned int>& _index)
	{
		m_Count = _index.size() * sizeof(unsigned int);

		this->Bind();
		DF_GLCALL(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, m_Count, _index.data()));
		this->Unbind();
	}

	IndexBuffer::IndexBuffer(std::vector<unsigned int>& _index)
	{
		DF_GLCALL(glGenBuffers(1, &m_IBO));
		this->Set(_index);
	}

	IndexBuffer::IndexBuffer()
	{
		DF_GLCALL(glGenBuffers(1, &m_IBO));
	}

	IndexBuffer::~IndexBuffer()
	{
		DF_GLCALL(glDeleteBuffers(1, &m_IBO));
	}
	
}