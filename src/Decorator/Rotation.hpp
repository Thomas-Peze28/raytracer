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
#include <cmath>

namespace Raytracer {

    namespace Object {
    
        class Rotation : public IPrimitive {
            public:
                Rotation(std::unique_ptr<IPrimitive> object, const Math::Vector3D &angles);
                ~Rotation() = default;

                HitResult hit(const Ray &ray) const override;
                Math::Vector3D pivot() const override;
                
            private:
                std::unique_ptr<IPrimitive> _object;
                Math::Vector3D _angles;
                Math::Point3D _pivot;

                Math::Vector3D rotate(const Math::Vector3D &vector, double angleX, double angleY, double angleZ) const;
                Math::Point3D rotate(const Math::Point3D &point, double angleX, double angleY, double angleZ) const;
        };
    }
}
