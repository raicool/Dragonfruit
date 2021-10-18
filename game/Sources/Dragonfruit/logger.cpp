#include "pch.h"

namespace DragonFruit
{
    void GLClearError()
    {
        while (glGetError() != GL_NO_ERROR);
    }

    bool GLLogCall(const char* function, const char* file, int line)
    {
        while (GLenum error = glGetError())
        {
            switch (error)
            {
            case GL_INVALID_ENUM:
                DF_LOG_WARN("GL_INVALID_ENUM : An unacceptable value is specified for an enumerated argument.");
                break;
            case GL_INVALID_VALUE:
                DF_LOG_WARN("GL_INVALID_OPERATION : A numeric argument is out of range.");
                break;
            case GL_INVALID_OPERATION:
                DF_LOG_WARN("GL_INVALID_OPERATION : The specified operation is not allowed in the current state.");
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                DF_LOG_WARN("GL_INVALID_FRAMEBUFFER_OPERATION : The framebuffer object is not complete.");
                break;
            case GL_OUT_OF_MEMORY:
                DF_LOG_ERROR("GL_OUT_OF_MEMORY : There is not enough memory left to execute the command.");
                break;
            case GL_STACK_UNDERFLOW:
                DF_LOG_WARN("GL_STACK_UNDERFLOW : An attempt has been made to perform an operation that would cause an internal stack to underflow.");
                break;
            case GL_STACK_OVERFLOW:
                DF_LOG_WARN("GL_STACK_OVERFLOW : An attempt has been made to perform an operation that would cause an internal stack to overflow.");
                break;
            default:
                DF_LOG_WARN("Unrecognized error " + error);
            }
            std::cout << std::endl;
            return false;
        }
        return true;
    }
};