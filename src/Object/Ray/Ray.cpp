/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Ray
*/

#include "Ray.hpp"

/** 
* @brief Construct a new Ray object
* @param origin The origin of the ray
* @param direction The direction of the ray
* @return A new Ray object
**/
Raytracer::Object::Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction) : _origin(origin), _direction(direction)
{
}

/** 
* @brief Assign the values of another Ray object to this Ray object
* @param other The other ray
* @return A reference to this Ray object
**/
Raytracer::Object::Ray& Raytracer::Object::Ray::operator=(const Ray &other)
{
    if (this != &other) {
        _origin = other._origin;
        _direction = other._direction;
    }
    return *this;
}