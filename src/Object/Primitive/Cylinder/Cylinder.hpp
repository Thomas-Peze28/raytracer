/*
** EPITECH PROJECT, 2026
** include
** File description:
** Cylinder
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
        class Cylinder : public IPrimitive
        {
            public:
                Cylinder() = default;
                Cylinder(const Math::Point3D &center, double radius, double height);
                Cylinder(const Math::Point3D &center, double radius, double height, const Math::Vector3D &color);
                Cylinder(const Cylinder &other);
                ~Cylinder() = default;

                Cylinder& operator=(const Cylinder &other);

                Math::Point3D _center;
                double _radius;
                double _height;

                Math::Vector3D _color;

                HitResult hit(const Ray &ray) const override;
        };
    };
};