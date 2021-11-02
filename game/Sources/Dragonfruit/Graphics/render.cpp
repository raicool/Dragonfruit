#include "pch.h"

#include "render.h"

namespace DragonFruit
{
    VertexArray Render::m_VertexArray;

    void Render::GenerateBuffer(uint32_t size)
    {
        DF_GLCALL(glGenBuffers(1, &m_VertexArray.m_VAO));
        DF_GLCALL(glBufferData(GL_ARRAY_BUFFER, size * sizeof(Quad), 0, GL_DYNAMIC_DRAW));
        DF_GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, 0, GL_DYNAMIC_DRAW));
    }

    void Render::DrawQuad(Quad& quad)
    {
        m_VertexArray.AddVertexBuffer(quad.Vertices);
        m_VertexArray.AddIndexBuffer(quad.Indices);
    }

    void Render::Draw(Window& window)
    {
        DF_GLCALL(glDrawElements(GL_TRIANGLES, m_VertexArray.m_IndexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr));
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Render::Render()
    {

    }
}