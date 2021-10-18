#include "pch.h"

#include "shader.h"

namespace DragonFruit
{
	void Shader::LoadShaders(const char* vertex_file_path, const char* fragment_file_path)
	{
		// Create the shaders
		GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		// Read the Vertex Shader code from the file
		std::string VertexShaderCode;
		std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
		if (VertexShaderStream.is_open())
		{
			std::stringstream sstr;
			sstr << VertexShaderStream.rdbuf();
			VertexShaderCode = sstr.str();
			VertexShaderStream.close();
		}
		else
		{
			DF_LOG_WARN("Impossible to open " << vertex_file_path << ". Are you in the right directory?");
			return;
		}

		// Read the Fragment Shader code from the file
		std::string FragmentShaderCode;
		std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
		if (FragmentShaderStream.is_open())
		{
			std::stringstream sstr;
			sstr << FragmentShaderStream.rdbuf();
			FragmentShaderCode = sstr.str();
			FragmentShaderStream.close();
		}
		else
		{
			DF_LOG_WARN("Impossible to open " << fragment_file_path << ". Are you in the right directory?");
			return;
		}

		GLint Result = GL_FALSE;
		int InfoLogLength;

		// Compile Vertex Shader
		DF_LOG_TEXT("Compiling shader : " << vertex_file_path);
		char const* VertexSourcePointer = VertexShaderCode.c_str();
		glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
		glCompileShader(VertexShaderID);

		// Check Vertex Shader
		glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0)
		{
			std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, VertexShaderErrorMessage.data());
			DF_LOG_ERROR(&VertexShaderErrorMessage[0]);
		}

		// Compile Fragment Shader
		DF_LOG_TEXT("Compiling shader : " << fragment_file_path);
		char const* FragmentSourcePointer = FragmentShaderCode.c_str();
		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
		glCompileShader(FragmentShaderID);

		// Check Fragment Shader
		glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0)
		{
			std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, FragmentShaderErrorMessage.data());
			DF_LOG_ERROR(&FragmentShaderErrorMessage[0]);
		}

		// Link the program
		DF_LOG_TEXT("Linking program");
		m_ProgramID = glCreateProgram();
		glAttachShader(m_ProgramID, VertexShaderID);
		glAttachShader(m_ProgramID, FragmentShaderID);
		glLinkProgram(m_ProgramID);

		// Check the program
		glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &Result);
		glGetProgramiv(m_ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0)
		{
			std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
			glGetProgramInfoLog(m_ProgramID, InfoLogLength, NULL, ProgramErrorMessage.data());
			DF_LOG_ERROR(&ProgramErrorMessage[0]);
		}

		glDetachShader(m_ProgramID, VertexShaderID);
		glDetachShader(m_ProgramID, FragmentShaderID);

		glDeleteShader(VertexShaderID);
		glDeleteShader(FragmentShaderID);

		// Bind the shader
		this->Bind();

		return;
	}

	void Shader::Bind()
	{
		glUseProgram(m_ProgramID);
	}

	Shader::Shader()
	{
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ProgramID);
	}

	void Shader::SendUniform1i(const char* identifier, int& value)
	{
		DF_GLCALL(glUniform1i
		(
			glGetUniformLocation(this->m_ProgramID, identifier),
			value
		));
	}

	void Shader::SendUniformMat4(const char* identifier, glm::mat4& matrix)
	{
		DF_GLCALL(glUniformMatrix4fv
		(
			glGetUniformLocation(this->m_ProgramID, identifier),
			1,
			GL_FALSE,
			&matrix[0][0]
		));
	}

	void Shader::SendUniformFloat(const char* identifier, float& value)
	{
		DF_GLCALL(glUniform1f
		(
			glGetUniformLocation(this->m_ProgramID, identifier),
			value
		));
	}

	void Shader::SendUniformFloat2(const char* identifier, std::vector<float>& value)
	{
		DF_GLCALL(glUniform2f
		(
			glGetUniformLocation(this->m_ProgramID, identifier),
			value[0],
			value[1]
		));
	}
}