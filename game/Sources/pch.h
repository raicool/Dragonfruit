#pragma once

#define DebugMode 1

// Other dependencies stuff
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <stb_image.h>

// Standard library stuff
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

// Dragonfruit
#include "dragonfruit/logger.h"

// Os specific
#ifdef _WIN32
	#include <windows.h>
#endif

// OpenGL stuff
#include <glew.h>
#include <glfw3.h>
#include <imgui.h>
#include <glm.hpp>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>