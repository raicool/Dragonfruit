#pragma once

#include "window.h"
#include "buffer.h"

namespace DragonFruit
{
    class Render
    {
    public:
		static void GenBuffers(GLsizei Size);
		static void NewVertex(std::vector<float>&);
		static void NewIndex(std::vector<unsigned int>&);
        static void Draw(Window& window_context);

        Render();

    private:
        static GLuint m_Count;
        static GLuint m_Offset;

        
    };
}