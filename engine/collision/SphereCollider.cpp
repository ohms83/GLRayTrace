#include "SphereCollider.h"

#include "geometry/Ray.h"

SphereCollider::SphereCollider(const Sphere& sphere)
{
    _sphere = sphere;
}

SphereCollider::~SphereCollider()
{

}

bool SphereCollider::isCollide(const Sphere& other) const
{
    return Collider::checkSphereCollision(_sphere.center, _sphere.radius, other.center, other.radius);
}

bool SphereCollider::isCollide(const Ray& ray) const
{
    return Collider::checkRaySphereCollision(ray.origin, ray.direction, _sphere.center, _sphere.radius);
}