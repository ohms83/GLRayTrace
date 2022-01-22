#pragma once

#include <glm/glm.hpp>

struct Ray
{
    /// Ray's origin.
    glm::vec3 origin;
    /// Ray's direction. NOTE: This parameter is not normalized.
    glm::vec3 direction;
};