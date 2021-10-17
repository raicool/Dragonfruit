#include "../../pch.h"

#include "camera.h"

namespace DragonFruit
{
    void OrthographicCamera::UpdateMatrix()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1), m_Position) 
            * glm::rotate(glm::mat4(1), m_Rotation, glm::vec3(0, 0, 1));

        m_ViewMatrix = glm::inverse(transform);
        m_VPMatrix = m_ViewMatrix * m_ProjectionMatrix;
    }

    void OrthographicCamera::SetPosition(glm::vec3 _position)
    {
        m_Position = _position;
        this->UpdateMatrix();
    }

    void OrthographicCamera::SetRotation(float _rotation)
    {
        m_Rotation = _rotation;
        this->UpdateMatrix();
    }

    OrthographicCamera::OrthographicCamera()
    {
    }

    OrthographicCamera::~OrthographicCamera()
    {
    }
}