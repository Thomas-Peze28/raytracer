/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Vector3D
*/

#pragma once

    #include <cmath>

namespace Raytracer
{
    namespace Math
    {
        class Vector3D
        {
            public:
                Vector3D();
                Vector3D(double x, double y, double z);
                ~Vector3D();

                float length() const;
                float dot(Vector3D v1) const;

                double _x;
                double _y;
                double _z;
        };
    };
};