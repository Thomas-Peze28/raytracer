/*
** EPITECH PROJECT, 2026
** include
** File description:
** Sphere
*/

#pragma once

    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "IPrimitive.hpp"

namespace Raytracer
{
    namespace Object
    {
        class Sphere : public IPrimitive
        {
            public:
                Sphere() = default;
                Sphere(const Math::Point3D &center, double radius);
                Sphere(const Math::Point3D &center, double radius, const Math::Vector3D &color);
                Sphere(const Sphere &other);
                ~Sphere() = default;

                Sphere& operator=(const Sphere &other);

                Math::Point3D _center;
                double _radius;

                Math::Vector3D _color;

                HitResult hit(const Ray &ray) const override;
                Math::Vector3D pivot() const override;
        };
    };
};