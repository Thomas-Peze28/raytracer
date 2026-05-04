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
                Camera(unsigned int width, unsigned int height);
                Camera(const Camera &other);
                ~Camera() = default;

                Camera& operator=(const Camera &other);

                Ray ray(double u, double v) const;

                unsigned int width() const;
                unsigned int height() const;

            private:
                Raytracer::Math::Point3D _origin;
                Rectangle3D _screen;
                unsigned int _width;
                unsigned int _height;
        };
    }
}
