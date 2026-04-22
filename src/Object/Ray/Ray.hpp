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
    namespace Object {
        class Ray
        {
            public:
                Ray();
                Ray(Math::Point3D point, Math::Vector3D vector);
                ~Ray();

                Math::Vector3D _vector;
                Math::Point3D _point;
        };
    }
};
