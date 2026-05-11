/*
** EPITECH PROJECT, 2026
** include
** File description:
** Plane
*/

#pragma once

    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "IPrimitive.hpp"
    #include "RTCError.hpp"

namespace Raytracer
{
    namespace Object
    {
        class Plane : public IPrimitive
        {
            public:
                Plane() = default;
                Plane(const char axis, float position, const Math::Vector3D &color);
                Plane(const Plane &other);
                ~Plane() = default;

                Plane& operator=(const Plane &other);

                char _axis;
                Math::Vector3D _normal;
                float _position;
                Math::Vector3D _color;

                HitResult hit(const Ray &ray) const override;
        };
    };
};