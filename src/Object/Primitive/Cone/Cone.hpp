/*
** EPITECH PROJECT, 2026
** include
** File description:
** Cone
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
        class Cone : public IPrimitive
        {
            public:
                Cone() = default;
                Cone(const Math::Point3D &center, double angle, double height);
                Cone(const Math::Point3D &center, double angle, double height, const Math::Vector3D &color);
                Cone(const Cone &other);
                ~Cone() = default;

                Cone& operator=(const Cone &other);

                Math::Point3D _center;
                double _angle;
                double _height;

                Math::Vector3D _color;

                HitResult hit(const Ray &ray) const override;
                Math::Vector3D pivot() const override;
        };
    };
};