/*
** EPITECH PROJECT, 2026
** include
** File description:
** Rectangle3D
*/

#pragma once

    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"

namespace Raytracer
{
    namespace Object
    {
        class Rectangle3D
        {
            public:
                Rectangle3D() = default;
                Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &bottom_side, const Math::Vector3D &left_side);
                Rectangle3D(const Rectangle3D &other);
                ~Rectangle3D() = default;
        
                Math::Point3D pointAt(double u, double v) const;

                Math::Point3D _origin;
                Math::Vector3D _bottom_side;
                Math::Vector3D _left_side;
        };
    };
};
