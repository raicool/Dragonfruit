#pragma once
#include "graphics/window.h"

#define DF_DEBUGLINE(x) if (DebugMode) x;

#define DF_ASSERT(x) if (!(x)) __debugbreak();

#define DF_GLCALL(x)\
    if (DebugMode) {\
    GLClearError();\
    x;\
    DF_ASSERT(GLLogCall(#x, __FILE__, __LINE__));}

void GLClearError();
bool GLLogCall(
    const char* function,
    const char* file,
    int line
);