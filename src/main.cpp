#include <iostream>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <vector>
#include "sstream"

#include "TestScene.h"

int main(int, char**) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    const size_t width  = 800;
    const size_t height = 600;
    GLFWwindow* window = glfwCreateWindow(width, height, "OpenGL Ray Trace", nullptr, nullptr);
    
    TestScene scene;
    scene.viewPortWidth = width;
    scene.viewPortHeight = height;
    scene.onEnter();

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        scene.update(1.f);
        scene.render();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
