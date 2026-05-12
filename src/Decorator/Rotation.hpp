/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Rotation
*/

#pragma once

#include "IPrimitive.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include <memory>

namespace Raytracer {

    namespace Object {
    
        class Rotation : public IPrimitive {
            public:
                Rotation(std::unique_ptr<IPrimitive> object, const Math::Vector3D &angles);
                ~Rotation() = default;

                HitResult hit(const Ray &ray) const override;
                
            private:
                std::unique_ptr<IPrimitive> _object;
                Math::Vector3D _angles;
        };
    }
}
