#include "RayCollider.h"

#include "geometry/Sphere.h"

RayCollider::RayCollider(const Ray& ray)
{
    _ray = ray;
}

RayCollider::~RayCollider()
{

}

bool RayCollider::isCollide(const Sphere& sphere) const
{
    return Collider::chcekRaySphereCollision(_ray.origin, _ray.direction, sphere.center, sphere.radius);
}

bool RayCollider::isCollide(const Ray& other) const
{
    return false;
}