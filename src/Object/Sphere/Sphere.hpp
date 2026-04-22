/*
** EPITECH PROJECT, 2026
** include
** File description:
** Sphere
*/

#ifndef SPHERE_H
    #define SPHERE_H

    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"

namespace Raytracer
{
    namespace Object
    {
        class Sphere {
            public:
                Sphere() = default;
                Sphere(const Math::Point3D &center, double radius);
                Sphere(const Sphere &other);
                ~Sphere() = default;

                Math::Point3D _center;
                double _radius;

                bool hit(const Ray &ray) const;

            private:
        };
    };
}

#endif /* SPHERE_H */