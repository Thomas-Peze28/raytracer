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
   // TODO
}

Raytracer::Math::Vector3D Raytracer::Object::Rotation::rotate(const Math::Vector3D &v, double angleX, double angleY, double angleZ) const
{
    // TODO
}

Raytracer::Math::Point3D Raytracer::Object::Rotation::rotate(const Math::Point3D &p, double angleX, double angleY, double angleZ) const
{
    // TODO
}