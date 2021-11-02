#include "pch.h"

#include "camera.h"

namespace DragonFruit
{
    void OrthographicCamera::Create(float l, float r, float b, float t)
    {
        m_ProjectionMatrix = glm::ortho(l, r, b, t);
        this->UpdateMatrix();
    }

    void OrthographicCamera::UpdateMatrix()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1), m_Position) 
            * glm::rotate(glm::mat4(1), m_Rotation, glm::vec3(0, 0, 1));

        m_ViewMatrix = glm::inverse(transform);
        m_VPMatrix = m_ViewMatrix * m_ProjectionMatrix;
    }

    void OrthographicCamera::SetPosition(glm::vec3 position)
    {
        m_Position = position;
        this->UpdateMatrix();
    }

    void OrthographicCamera::SetRotation(float rotation)
    {
        m_Rotation = rotation;
        this->UpdateMatrix();
    }

    OrthographicCamera::OrthographicCamera()
    {
    }

    OrthographicCamera::~OrthographicCamera()
    {
    }


}