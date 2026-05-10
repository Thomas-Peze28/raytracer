/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Plane
*/

#include "Plane.hpp"

/** 
 * @brief Construct a new Plane object
 * @param axis The axis of the plane
 * @param position The position of the plane
 * @param color The color of the plane
 * @return A new Plane object with the specified color
*/
Raytracer::Object::Plane::Plane(const char axis, float position, const Math::Vector3D &color) : _axis(axis), _position(position), _color(color)
{
    if (_axis == 'x') {
        _normal = Math::Vector3D(0.0f, -1.0f, 0.0f);
    } else if (_axis == 'y') {
        _normal = Math::Vector3D(1.0f, 0.0f, 0.0f);
    } else if (_axis == 'z') {
        _normal = Math::Vector3D(0.0f, 0.0f, 1.0f);
    } else {
        throw std::invalid_argument("Invalid axis for plane: " + std::string(1, _axis));
    }
}

/**
 * @brief Construct a new Plane object by copying another Plane object
 * @param other The other plane
 * @return A new Plane object
*/
Raytracer::Object::Plane::Plane(const Plane &other) : _axis(other._axis), _normal(other._normal), _position(other._position), _color(other._color)
{
}

/**
* @brief Assign the values of another Plane object to this Plane object
* @param other The other plane
* @return A reference to this Plane object
**/
Raytracer::Object::Plane& Raytracer::Object::Plane::operator=(const Plane &other)
{
    if (this != &other) {
        _axis = other._axis;
        _normal = other._normal;
        _position = other._position;
        _color = other._color;
    }
    return *this;
}

/**
* @brief Check if a ray hits the plane
* @param ray The ray to check
* @return The hit result containing whether the ray hits the plane, the distance to the hit point, the hit point itself, and the normal at the hit point
**/
Raytracer::HitResult Raytracer::Object::Plane::hit(const Ray &ray) const
{
    HitResult result;

    float denom = _normal.dot(ray._direction);

    if (denom != 0) {

        float t = (_position - _normal.dot(ray._origin - Math::Point3D(0.0f, 0.0f, 0.0f))) / denom;

        if (t >= 0) {
            result.is_hit = true;
            result.t = t;
            result.point = ray._origin + ray._direction * t;
            result.normal = _normal;
            result.color = _color;
        } else {
            result.is_hit = false;
        }
    } else {
        result.is_hit = false;
    }
    return result;
}