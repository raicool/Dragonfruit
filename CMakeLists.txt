cmake_minimum_required(VERSION 3.8.0)
project(dragonfruit VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE DF_SOURCE "game/sources/*.cpp")
file(GLOB_RECURSE DF_INCLUDE "game/sources/*.h")
file(GLOB_RECURSE DF_IMGUI_CPP 
    "game/dependencies/imgui/imgui.cpp"
    "game/dependencies/imgui/imgui_widgets.cpp"
    "game/dependencies/imgui/imgui_tables.cpp"
    "game/dependencies/imgui/imgui_draw.cpp"
    "game/dependencies/imgui/imgui_demo.cpp"
    "game/dependencies/imgui/backends/imgui_impl_sdlrenderer.cpp"
    "game/dependencies/imgui/backends/imgui_impl_opengl3.cpp"
    "game/dependencies/imgui/backends/imgui_impl_sdl.cpp")

add_executable(dragonfruit ${DF_IMGUI_CPP} ${DF_INCLUDE} ${DF_SOURCE} )

target_precompile_headers(dragonfruit PRIVATE "game/sources/pch.h")

target_include_directories(dragonfruit PRIVATE 
    "game/sources"
    "game/dependencies/imgui"
    "game/dependencies/glm"
    "game/dependencies/entt/src"
    "game/dependencies/spdlog/include"
)

set(SDL_STATIC ON CACHE BOOL "USE STATIC SDL" FORCE)
set(SDL_SHARED OFF CACHE BOOL "USE SHARED SDL" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "BUILD SHARED LIBS" FORCE)

add_subdirectory(game/dependencies/SDL)
add_subdirectory(game/dependencies/SDL_image)
add_subdirectory(game/dependencies/glm)
add_subdirectory(game/dependencies/entt)

file(COPY "game/resources" DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(dragonfruit "SDL2-static" "SDL2main" "SDL2_image")