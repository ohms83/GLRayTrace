#pragma once

#include "Collider.h"

#include "geometry/Sphere.h"

class SphereCollider : public Collider
{
public:
    SphereCollider(const Sphere& sphere);
    virtual ~SphereCollider();
    
    bool isCollide(const Sphere& sphere) const override;
    bool isCollide(const Ray& ray) const override;

protected:
    Sphere _sphere;
};