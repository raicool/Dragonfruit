#include "pch.h"

#include "app.h"

int main() 
{
    using namespace DragonFruit;

    Window::InitGLFW();
    Application App;

    while (!glfwWindowShouldClose(App.GetWindow()))
        App.OnUpdate();

    App.Shutdown();
}