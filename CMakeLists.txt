cmake_minimum_required(VERSION 3.0.0)
project(dragonfruit VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dragonfruit
    "game/sources/main.cpp"
    "game/sources/app.cpp"
    "game/sources/system/scene.cpp"
    "game/sources/graphics/window.cpp"
    "game/sources/system/resource.cpp"
    "game/sources/system/entity.cpp"
    "game/sources/system/scene.cpp"

    "game/dependencies/imgui/imgui.cpp"
    "game/dependencies/imgui/imgui_widgets.cpp"
    "game/dependencies/imgui/imgui_tables.cpp"
    "game/dependencies/imgui/imgui_draw.cpp"
    "game/dependencies/imgui/imgui_demo.cpp"
    "game/dependencies/imgui/backends/imgui_impl_sdlrenderer.cpp"
    "game/dependencies/imgui/backends/imgui_impl_opengl3.cpp"
    "game/dependencies/imgui/backends/imgui_impl_sdl.cpp"
 "game/sources/system/debug.cpp" "game/sources/system/gui/hierarchy.cpp" "game/sources/system/layers.h" )

target_precompile_headers(dragonfruit PRIVATE 
    "game/sources/pch.h"
)

target_include_directories(dragonfruit PRIVATE 
    "game/sources"
    "game/dependencies/imgui"
    "game/dependencies/glm"
    "game/dependencies/entt/src"
    "game/dependencies/spdlog/include"
)

set(SDL_STATIC ON CACHE BOOL "wow" FORCE)
set(SDL_SHARED OFF CACHE BOOL "wow" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "wow" FORCE)

add_subdirectory(game/dependencies/SDL)
add_subdirectory(game/dependencies/SDL_image)
add_subdirectory(game/dependencies/glm)
add_subdirectory(game/dependencies/entt)

file(COPY game/resources DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(dragonfruit SDL2-static SDL2main SDL2_image)
