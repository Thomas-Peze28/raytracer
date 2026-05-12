/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Translation
*/

#include "Translation.hpp"

Raytracer::Object::Translation::Translation(std::unique_ptr<IPrimitive> object, const Math::Vector3D &offset)
    : _object(std::move(object)), _offset(offset)
{
}

Raytracer::HitResult Raytracer::Object::Translation::hit(const Ray &ray) const
{
    Math::Point3D moved_origin = ray._origin - _offset;
    
    Ray moved_ray(moved_origin, ray._direction);

    HitResult result = _object->hit(moved_ray);

    if (result.is_hit) {
        result.point = result.point + _offset;
    }

    return result;
}