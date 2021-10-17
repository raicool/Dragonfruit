#pragma once

#include <gtc/matrix_transform.hpp>

namespace DragonFruit
{
	class OrthographicCamera
	{
	public:
		void Create(float l, float r, float b, float t) { m_ProjectionMatrix = glm::ortho(l, r, b, t); }

		void SetPosition(glm::vec3);
		const glm::vec3 Position() { return m_Position; }

		void SetRotation(float);
		const float RotationDeg() { return glm::degrees(m_Rotation); }
		const float RotationRad() { return m_Rotation; }
		
		OrthographicCamera();
		~OrthographicCamera();
	private:
		void UpdateMatrix();

		glm::vec3 m_Position;
		glm::vec3 m_Direction;
		float m_Rotation;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_VPMatrix;
	};
}