#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <memory>

#include "collision/Collider.h"

class Node
{
public:
    Node();
    virtual ~Node();

    glm::mat4 getTransform() const;

public:
    std::unique_ptr<Collider> collider;

    glm::vec3 position = {};
    glm::quat rotation = { 0, 0, 0, 1 };
    glm::vec3 scale = { 1, 1, 1 };
};