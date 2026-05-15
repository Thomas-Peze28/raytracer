/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Scale
*/

#pragma once

#include "IPrimitive.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"

#include <memory>

namespace Raytracer {

    namespace Object {

        class Scale : public IPrimitive {
            public:
                Scale(std::unique_ptr<IPrimitive> object, const Math::Vector3D &factors);
                ~Scale() = default;

                HitResult hit(const Ray &ray) const override;
                Math::Vector3D pivot() const override;

            private:
                std::unique_ptr<IPrimitive> _object;
                Math::Vector3D _factors;
                Math::Point3D _pivot;

                Math::Vector3D transformVector(const Math::Vector3D &vector) const;
                Math::Point3D transformPoint(const Math::Point3D &point) const;
                double computeT(const Ray &ray, const Math::Point3D &point) const;
        };
    }
}