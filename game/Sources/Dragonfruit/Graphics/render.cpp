#include "../../pch.h"

#include "render.h"

namespace DragonFruit
{
    GLuint Render::m_count;
    GLuint Render::m_offset;

    void Render::GenBuffers(GLsizei Size)
    {
    }

    void Render::NewVertex(std::vector<float>& _vertex)
    {
    }

    void Render::NewIndex(std::vector<unsigned int>& _index)
    {
    }

    void Render::Draw(Window& window)
    {
        DF_GLCALL(glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, nullptr));

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}