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

    std::shared_ptr<Node> newNode();
    void addNode(std::shared_ptr<Node> node);

    virtual void update(float dt) {}
    virtual void render() {}
    virtual void onEnter() {}

protected:
    std::vector<std::shared_ptr<Node>> _nodeList;
};