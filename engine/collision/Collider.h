#pragma once

#include <vector>
#include <glm/glm.hpp>

class Sphere;
class Ray;

// Collision data
struct Collision
{
    glm::vec3 contactPoint;
    glm::vec3 normal;
};

class Collider
{
public:
    Collider();
    virtual ~Collider();
    
    virtual bool isCollide(const Sphere& sphere) const = 0;
    virtual bool isCollide(const Ray& ray) const = 0;

    static bool chcekSphereCollision(const glm::vec3& center1, float radius1,
                                     const glm::vec3& center2, float radius2);

    static bool chcekRaySphereCollision(const glm::vec3& rayOrg, const glm::vec3& rayDir,
                                        const glm::vec3& sphereCenter, float radius);
};
