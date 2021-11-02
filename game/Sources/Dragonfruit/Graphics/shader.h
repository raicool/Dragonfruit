#pragma once

namespace DragonFruit
{
	class Shader
	{
	public:
		void LoadShaders(const char*, const char*);

		void SendUniform1i(const char* identifier, int& value);
		void SendUniformMat4(const char* identifier, glm::mat4& matrix);
		void SendUniformFloat(const char* identifier, float& value);
		void SendUniformFloat2(const char* identifier, std::vector<float>& value);

		void Bind();

		uint32_t GetProgramID() { return m_ProgramID; }

		Shader();
		~Shader();

		operator uint32_t () { return m_ProgramID; };

	private:
		uint32_t m_ProgramID;
	};
}