#pragma once

constexpr const char* Title = "OpenGL";
constexpr int WinWidth  = 1326;
constexpr int WinHeight = 720;
constexpr bool VSync = true;

namespace DragonFruit
{
    class Window
    {
    public:
        int width = WinWidth;
        int height = WinHeight;

        void SetClearColor(GLclampf red, GLclampf green, GLclampf blue);
        void Destroy();
        void Update();
        
        static void InitGLFW();

        Window();

        operator GLFWwindow* () const { return m_Window; }

    private:
        GLFWwindow* m_Window = glfwCreateWindow(WinWidth, WinHeight, Title, NULL, NULL);

        static void ErrCallback(int, const char*);
    };
}