/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Ray
*/

#include "Ray.hpp"

Raytracer::Object::Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction) : _origin(origin), _direction(direction)
{
}