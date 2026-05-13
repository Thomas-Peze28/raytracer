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
                Camera(unsigned int width, unsigned int height, unsigned int fov);
                Camera(unsigned int width, unsigned int height, unsigned int fov, const Math::Point3D &lookFrom, const Math::Point3D &lookAt, const Math::Vector3D &up);
                Camera(const Camera &other);
                ~Camera() = default;

                Camera& operator=(const Camera &other);

                Ray ray(double u, double v) const;

                unsigned int width() const;
                unsigned int height() const;
                unsigned int fov() const;
                Math::Point3D lookFrom() const;
                Math::Point3D lookAt() const;
                Math::Vector3D up() const;

            private:
                Raytracer::Math::Point3D _origin;
                Rectangle3D _screen;
                unsigned int _width;
                unsigned int _height;
                unsigned int _fov;

                Math::Point3D _lookFrom;
                Math::Point3D _lookAt;
                Math::Vector3D _up; 
        };
    }
}
