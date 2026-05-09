/*
** EPITECH PROJECT, 2026
** include
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_H
    #define DIRECTIONALLIGHT_H

    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "ILight.hpp"

namespace Raytracer
{
    namespace Object
    {
        class DirectionalLight : public ILight {
            public:
                DirectionalLight();
                DirectionalLight(const Math::Vector3D &direction, const Math::Vector3D &color);
                DirectionalLight(const Math::Vector3D &direction, const Math::Vector3D &color, const float intensity);
                ~DirectionalLight() = default;
        
                const Math::Vector3D &direction() const;
                const Math::Vector3D &color() const override;
                float intensity() const override;

                Math::Vector3D getDirectionToLight(const Math::Point3D &hit_point) const override;
                float getDistanceToLight(const Math::Point3D &hit_point) const override;
        
            private:
                Math::Vector3D _direction;
                Math::Vector3D _color;
                float _intensity;
        };
    }
}

#endif /* DIRECTIONALLIGHT_H */