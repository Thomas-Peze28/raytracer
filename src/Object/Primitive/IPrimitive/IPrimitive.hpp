

/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** IPrimitive
*/

#ifndef IPRIMITIVE_HPP
    #define IPRIMITIVE_HPP

    #include "Ray.hpp"
    #include "Point3D.hpp"
    #include "Vector3D.hpp"

namespace Raytracer
{
    struct HitResult {
        bool is_hit;
        double t;
        Math::Point3D point;
        Math::Vector3D normal;
        Math::Vector3D color;
    };

    namespace Object
    {
        class IPrimitive {
            public:
                virtual ~IPrimitive() = default;

                virtual HitResult hit(const Ray &ray) const = 0;
        };
    }
}

#endif /* IPRIMITIVE_HPP */