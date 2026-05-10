/*
** EPITECH PROJECT, 2026
** include
** File description:
** PointLight
*/

#ifndef POINTLIGHT_H
    #define POINTLIGHT_H

    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "ILight.hpp"

namespace Raytracer
{
    namespace Object
    {
        class PointLight : public ILight {
            public:
                PointLight();
                PointLight(const Math::Point3D &position, const Math::Vector3D &color);
                PointLight(const Math::Point3D &position, const Math::Vector3D &color, const float intensity);
                ~PointLight() = default;
        
                const Math::Point3D &position() const;
                const Math::Vector3D &color() const override;
                float intensity() const override;

                Math::Vector3D getDirectionToLight(const Math::Point3D &hit_point) const override;
                float getDistanceToLight(const Math::Point3D &hit_point) const override;
        
            private:
                Math::Point3D _position;
                Math::Vector3D _color;
                float _intensity;
        };
    }
}

#endif /* POINTLIGHT_H */