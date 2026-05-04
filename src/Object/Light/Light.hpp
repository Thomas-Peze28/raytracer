/*
** EPITECH PROJECT, 2026
** include
** File description:
** Light
*/

#ifndef LIGHT_H
    #define LIGHT_H

    #include "Point3D.hpp"
    #include "Vector3D.hpp"

namespace Raytracer
{
    namespace Object
    {
        class Light {
            public:
                Light();
                Light(const Math::Point3D &position, const Math::Vector3D &color);
                Light(const Math::Point3D &position, const Math::Vector3D &color, const float intensity);
                ~Light() = default;
        
                const Math::Point3D &position() const;
                const Math::Vector3D &color() const;
                float intensity() const;
        
            private:
                Math::Point3D _position;
                Math::Vector3D _color;
                float _intensity;
        };
    }
}

#endif /* LIGHT_H */