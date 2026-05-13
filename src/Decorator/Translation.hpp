/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Translation
*/

#pragma once

#include "IPrimitive.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include <memory>

namespace Raytracer {

    namespace Object {
    
        class Translation : public IPrimitive {
            public:
                Translation(std::unique_ptr<IPrimitive> object, const Math::Vector3D &offset);
                ~Translation() = default;

                HitResult hit(const Ray &ray) const override;
                Math::Vector3D pivot() const override;
                
            private:
                std::unique_ptr<IPrimitive> _object;
                Math::Vector3D _offset;
        };
    }
}
