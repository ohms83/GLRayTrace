#pragma once

#include "Collider.h"
#include "geometry/Ray.h"

class RayCollider : public Collider
{
public:
    RayCollider(const Ray& ray);
    virtual ~RayCollider();

    bool isCollide(const Sphere& sphere) const override;
    bool isCollide(const Ray& other) const override;

protected:
    Ray _ray;
};