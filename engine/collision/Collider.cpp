#include "Collider.h"

#include <iostream>

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::chcekSphereCollision(const glm::vec3& center1, float radius1,
                                    const glm::vec3& center2, float radius2)
{
    float distance = glm::length(center1 - center2);
    return distance <= radius1 + radius2;
}

bool Collider::chcekRaySphereCollision(const glm::vec3& rayOrg, const glm::vec3& rayDir,
                                       const glm::vec3& sphereCenter, float radius)
{
    glm::vec3 oc = rayOrg - sphereCenter;
    glm::vec3 u = glm::normalize(rayDir);
    // float a = glm::dot(rayDir, rayDir);
    float b = glm::dot(oc, u);
    float c = glm::dot(oc, oc) - (radius * radius);
    float h = (b * b) - c;

    if (h < 0) {
        return false;
    }
    // TODO: Return collision data
    // if (h > 0)
    // {
    //     h = glm::sqrt(h);
    //     float d1 = -b + h;
    //     float d2 = -b - h;
    //     float rayLength = glm::length(rayDir);
    //     glm::vec3 p1 = rayOrg + (u * d1);
    //     glm::vec3 p2 = rayOrg + (u * d2);
    //     float dot1 = glm::dot(u, p1);
    //     float dot2 = glm::dot(u, p2);

    //     std::cout << "d1:" << d1 << " d2:" << d2 << " rayLength:" << rayLength << "\n";
    //     std::cout << "dot1:" << dot1 << " dot2:" << dot2 << std::endl;
    // }

    return true;
}