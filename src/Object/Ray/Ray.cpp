/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Ray
*/

#include "Ray.hpp"

Raytracer::Object::Ray::Ray() : _vector(Math::Vector3D()), _point(Math::Point3D())
{
}

Raytracer::Object::Ray::Ray(Math::Point3D point, Math::Vector3D vector)
{
    _vector = vector;
    _point = point;
}

Raytracer::Object::Ray::~Ray()
{
}