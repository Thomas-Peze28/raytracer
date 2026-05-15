/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Scale
*/

#include "Scale.hpp"
#include "RTCError.hpp"

#include <cmath>

Raytracer::Object::Scale::Scale(std::unique_ptr<IPrimitive> object, const Math::Vector3D &factors)
    : _object(std::move(object)), _factors(factors), _pivot(_object->pivot()._x, _object->pivot()._y, _object->pivot()._z)
{
    if (_factors._x == 0.0 || _factors._y == 0.0 || _factors._z == 0.0) {
        throw ErrorMajor("Scale factors must be non-zero");
    }
}

Raytracer::HitResult Raytracer::Object::Scale::hit(const Ray &ray) const
{
    Math::Point3D local_origin(
        ray._origin._x - _pivot._x,
        ray._origin._y - _pivot._y,
        ray._origin._z - _pivot._z
    );

    Ray scaled_ray(
        Math::Point3D(
            _pivot._x + (local_origin._x / _factors._x),
            _pivot._y + (local_origin._y / _factors._y),
            _pivot._z + (local_origin._z / _factors._z)
        ),
        Math::Vector3D(
            ray._direction._x / _factors._x,
            ray._direction._y / _factors._y,
            ray._direction._z / _factors._z
        )
    );

    HitResult result = _object->hit(scaled_ray);

    if (!result.is_hit) {
        return result;
    }

    result.point = transformPoint(result.point);
    result.normal = transformVector(result.normal).normalized();
    result.t = computeT(ray, result.point);
    return result;
}

Raytracer::Math::Vector3D Raytracer::Object::Scale::pivot() const
{
    return Math::Vector3D(_pivot._x, _pivot._y, _pivot._z);
}

Raytracer::Math::Vector3D Raytracer::Object::Scale::transformVector(const Math::Vector3D &vector) const
{
    return Math::Vector3D(vector._x / _factors._x, vector._y / _factors._y, vector._z / _factors._z);
}

Raytracer::Math::Point3D Raytracer::Object::Scale::transformPoint(const Math::Point3D &point) const
{
    return Math::Point3D(
        _pivot._x + ((point._x - _pivot._x) * _factors._x),
        _pivot._y + ((point._y - _pivot._y) * _factors._y),
        _pivot._z + ((point._z - _pivot._z) * _factors._z)
    );
}

double Raytracer::Object::Scale::computeT(const Ray &ray, const Math::Point3D &point) const
{
    Math::Vector3D hit_vector = point - ray._origin;
    Math::Vector3D direction = ray._direction;
    double direction_length_sq = direction.dot(direction);

    if (direction_length_sq == 0.0) {
        return 0.0;
    }

    return hit_vector.dot(direction) / direction_length_sq;
}