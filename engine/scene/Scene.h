#pragma once

#include "Node.h"
#include "Camera.h"

#include <memory>
#include <vector>

class Scene
{
public:
    Scene();
    virtual ~Scene();

    std::shared_ptr<Node> addNode();

    virtual void update(float dt) {}
    virtual void render() {}
    virtual void onEnter() {}

public:
    Camera camera;

protected:
    std::vector<std::shared_ptr<Node>> _nodeList;
};