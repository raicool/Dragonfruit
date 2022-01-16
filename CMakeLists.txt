cmake_minimum_required(VERSION 3.0.0)
project(dragonfruit VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dragonfruit
    game/sources/main.cpp
    game/sources/system/app.cpp
    game/sources/system/entity.cpp
    game/sources/system/manager.cpp
    game/sources/graphics/quad.cpp
    
    game/sources/graphics/window.cpp

    game/dependencies/imgui/imgui.cpp
    game/dependencies/imgui/imgui_widgets.cpp
    game/dependencies/imgui/imgui_tables.cpp
    game/dependencies/imgui/imgui_draw.cpp
    game/dependencies/imgui/imgui_demo.cpp
)
target_precompile_headers(dragonfruit PRIVATE game/sources/pch.h)

target_include_directories(dragonfruit PRIVATE game/sources game/dependencies/imgui)

set(SDL_STATIC ON CACHE BOOL "wow" FORCE)
set(SDL_SHARED OFF CACHE BOOL "wow" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "wow" FORCE)

add_subdirectory(game/dependencies/SDL)
add_subdirectory(game/dependencies/SDL_image)

file(COPY game/resources DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(dragonfruit SDL2-static SDL2main SDL2_image)
