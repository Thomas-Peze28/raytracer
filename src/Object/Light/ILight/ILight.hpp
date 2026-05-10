/*
** EPITECH PROJECT, 2026
** include
** File description:
** ILight
*/

#ifndef ILIGHT_H
    #define ILIGHT_H

    #include "Point3D.hpp"
    #include "Vector3D.hpp"

namespace Raytracer
{
    namespace Object
    {
        class ILight {
            public:
                virtual ~ILight() = default;

                virtual Math::Vector3D getDirectionToLight(const Math::Point3D &hit_point) const = 0;
                virtual float getDistanceToLight(const Math::Point3D &hit_point) const = 0;

                virtual const Math::Vector3D &color() const = 0;
                virtual float intensity() const = 0;
        };
    }
}

#endif /* ILIGHT_H */
