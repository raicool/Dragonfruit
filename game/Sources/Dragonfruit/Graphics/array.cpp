#include "pch.h"

#include "array.h"

namespace DragonFruit
{
	void VertexArray::Bind() const
	{
		glBindVertexArray(m_VAO);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddVertexBuffer(VertexBuffer buffer)
	{
		this->Bind();
		buffer.Bind();
		
		DF_GLCALL(glEnableVertexAttribArray(m_VertexIndex));
		DF_GLCALL(glEnableVertexAttribArray(m_VertexIndex + 1));
		DF_GLCALL(glVertexAttribPointer(m_VertexIndex,     3, GL_FLOAT, GL_FALSE, 0, nullptr)); // Position
		DF_GLCALL(glVertexAttribPointer(m_VertexIndex + 1, 2, GL_FLOAT, GL_FALSE, 24, nullptr)); // Texture Coords
		DF_GLCALL(glDisableVertexAttribArray(m_VertexIndex));
		DF_GLCALL(glDisableVertexAttribArray(m_VertexIndex + 1));

		DF_LOG_TEXT("hello" << m_VertexIndex);

		m_VertexBuffer.push_back(buffer);

		m_VertexIndex++;
		m_VertexOffset += buffer.GetSize();
	}

	void VertexArray::AddIndexBuffer(IndexBuffer _index)
	{
		this->Bind();
		m_IndexBuffer = _index;
	}

	VertexArray::VertexArray() 
	{ 
		DF_GLCALL(glCreateVertexArrays(1, &m_VAO)); 
	}

	VertexArray::~VertexArray() 
	{
		DF_GLCALL(glDeleteVertexArrays(1, &m_VAO)); 
	}
}