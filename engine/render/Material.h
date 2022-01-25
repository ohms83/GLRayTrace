#pragma once

#include <glm/glm.hpp>

struct Material
{
    glm::vec3 ambient;
    glm::vec3 albedo;
    glm::vec3 specular;
    float shininess;
};