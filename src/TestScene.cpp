#include "TestScene.h"

#include "engine/collision/SphereCollider.h"
#include "engine/collision/RayCollider.h"
#include "engine/util/PPM.h"

#include <iostream>

TestScene::TestScene()
{
}

TestScene::~TestScene()
{

}

void TestScene::onEnter()
{
    camera.setViewPort(viewPortWidth, viewPortHeight);
    camera.setPerspective(45.f, (float)viewPortWidth / (float)viewPortHeight, 0.01f, 100.f);
    
    Sphere sphere = { glm::vec3 { 0.f, 0.f, -10.f }, 5.f };

    std::vector<glm::vec3> pixels(viewPortWidth * viewPortHeight);
    const glm::vec3 blue(120.f, 170.f, 255.f);
    const glm::vec3 white(255.f, 255.f, 255.f);
    const glm::vec3 red(255.f, 80.f, 100.f);
    uint32_t index = 0;

    auto paintImage = [&](const Ray& ray, uint32_t x, uint32_t y) {
        uint32_t index = x + (viewPortWidth * y);
        auto& pixel = pixels[index];
        // std::cout << "x=" << x << " y=" << y << " index=" << index << '\n';

        if(RayCollider(ray).isCollide(sphere))
        {
            pixel = red;
        }
        else
        {
            float t = (float)y / (float)viewPortHeight;
            float dt = 1.f - t;
            pixel.r = blue.r * dt + white.r * t;
            pixel.g = blue.g * dt + white.g * t;
            pixel.b = blue.b * dt + white.b * t;
        }
    };
    camera.castScannerRay(0, 0, viewPortWidth, viewPortHeight, paintImage);
    PPM::write(WRITABLE_PATH"/test.ppm", pixels, viewPortWidth, viewPortHeight);
}

void TestScene::update(float dt)
{

}

void TestScene::render()
{

}