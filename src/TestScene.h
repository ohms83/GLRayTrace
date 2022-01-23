#pragma once

#include "engine/engine.h"

class TestScene : public Scene
{
public:
    TestScene();
    virtual ~TestScene();

    void onEnter() override;
    void update(float dt) override;
    void render() override;

    uint32_t viewPortWidth = 0;
    uint32_t viewPortHeight = 0;
};