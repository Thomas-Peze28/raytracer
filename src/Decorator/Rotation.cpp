/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Rotation
*/

#include "Rotation.hpp"

Raytracer::Object::Rotation::Rotation(std::unique_ptr<IPrimitive> object, const Math::Vector3D &angles)
    : _object(std::move(object)), _angles(angles)
{
}

Raytracer::HitResult Raytracer::Object::Rotation::hit(const Ray &ray) const
{
   
}