#include "../../pch.h"

#include "window.h"

namespace DragonFruit
{
    void Window::InitGLFW()
    {
        DF_DEBUGLINE(glfwSetErrorCallback(Window::ErrCallback));
        DF_ASSERT(glfwInit());
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // using OpenGL 3.2
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        ImGui::CreateContext();
    }

    void Window::Update()
    {
        glfwGetWindowSize(this->m_Window, &width, &height);
        DF_GLCALL(glViewport(0, 0, width, height));
    }

    void Window::Destroy()
    {
        glfwSetWindowShouldClose(this->m_Window, true);
        glfwTerminate();
    }

    void Window::SetClearColor(GLclampf red, GLclampf green, GLclampf blue)
    {
        glClearColor(red, green, blue, 1.0);
    }

    void Window::ErrCallback(int error, const char* msg)
    {
        printf("[%i] %s", error, msg);
    }

    Window::Window()
    {
        glfwMakeContextCurrent(this->m_Window);
        glfwSwapInterval(VSync);
        glewInit();

        DF_LOG_INFO("Using OpenGL " << glGetString(GL_VERSION));
        DF_LOG_INFO("       RENDERER: " << glGetString(GL_RENDERER));
        DF_LOG_INFO("       VENDOR:   " << glGetString(GL_VENDOR));
    }
}