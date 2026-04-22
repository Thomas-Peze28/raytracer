/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Ray
*/

#pragma once

    #include "Vector3D.hpp"
    #include "Point3D.hpp"

namespace Raytracer
{
    namespace Object
    {
        class Ray {
            public:
                Ray() = default;
                Ray(const Math::Point3D &origin, const Math::Vector3D &direction);
                ~Ray() = default;
            
                Math::Point3D _origin;
                Math::Vector3D _direction;
            
            private:
        };
    };
};
