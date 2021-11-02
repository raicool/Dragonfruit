#pragma once

#include "window.h"
#include "buffer.h"
#include "array.h"
#include "quad.h"

namespace DragonFruit
{
    class Render
    {
    public:
		static void GenerateBuffer(uint32_t size);
		static void DrawQuad(Quad& quad);
        static void Draw(Window& window_context);

        Render();

    private:
        static uint32_t m_Count;
        static uint32_t m_Offset;

        static VertexArray m_VertexArray;
    };
}