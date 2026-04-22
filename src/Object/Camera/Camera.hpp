/*
** EPITECH PROJECT, 2026
** include
** File description:
** Camera
*/

#pragma once

    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "Rectangle3D.hpp"

namespace Raytracer
{
    namespace Object
    {
        class Camera
        {
            public:
                Camera();
                Camera(Math::Point3D origin, Rectangle3D screen);
                Camera(const Camera &other);
                ~Camera() = default;

                Ray ray(double u, double v) const;

            private:
                Math::Point3D _origin;
                Rectangle3D _screen;
        };
    }
}
