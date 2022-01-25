#pragma once

#include "Node.h"

#include <glm/glm.hpp>

class Light : public Node
{
public:
    enum Type
    {
        AMBIENT,
        POINT,
        DIRECTIONAL,
        SPOTLIGHT,
    };

    struct Attenuation
    {
        float constant;
        float linear;
        float quadratic;
    };

public:
    glm::vec3 color {};
    glm::vec3 direction {};
    Attenuation attenuation = {};
    /// Cut off radius of @c SPOTLIGHT in degree.
    float cutOff = 0.f;
};