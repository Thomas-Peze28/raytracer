/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

/** 
 * @brief Construct a new Cylinder object
 * @param center The center of the cylinder
 * @param radius The radius of the cylinder
 * @param height The height of the cylinder
 * @return A new Cylinder object with red default color
**/
Raytracer::Object::Cylinder::Cylinder(const Math::Point3D &center, double radius, double height) : _center(center), _radius(radius), _height(height), _color(255, 0, 0)
{
}

/** 
 * @brief Construct a new Cylinder object
 * @param center The center of the cylinder
 * @param radius The radius of the cylinder
 * @param height The height of the cylinder
 * @param color The color of the cylinder
 * @return A new Cylinder object with the specified color
**/
Raytracer::Object::Cylinder::Cylinder(const Math::Point3D &center, double radius, double height, const Math::Vector3D &color) : _center(center), _radius(radius), _height(height), _color(color)
{
}

/**
 * @brief Construct a new Cylinder object by copying another Cylinder object
 * @param other The other cylinder to copy
 * @return A new Cylinder object that is a copy of the other cylinder
**/
Raytracer::Object::Cylinder::Cylinder(const Cylinder &other) : _center(other._center), _radius(other._radius), _height(other._height), _color(other._color)
{
}

/**
* @brief Assign the values of another Cylinder object to this Cylinder object
* @param other The other cylinder
* @return A reference to this Cylinder object
**/
Raytracer::Object::Cylinder& Raytracer::Object::Cylinder::operator=(const Cylinder &other)
{
    if (this != &other) {
        _center = other._center;
        _radius = other._radius;
        _height = other._height;
        _color = other._color;
    }
    return *this;
}

/**
* @brief Check if a ray hits the cylinder
* @param ray The ray to check
* @return The hit result containing whether the ray hits the cylinder, the distance to the hit point, the hit point itself, and the normal at the hit point
**/
Raytracer::HitResult Raytracer::Object::Cylinder::hit(const Ray &ray) const
{
    HitResult result;
    Math::Vector3D originToCenter = ray._origin - _center;
    result.is_hit = false;

    float a = (ray._direction._x * ray._direction._x) + (ray._direction._z * ray._direction._z);
    if (a <= 0.0)
        return result;
    float b = 2.0 * ((originToCenter._x * ray._direction._x) + (originToCenter._z * ray._direction._z));
    float c = (originToCenter._x * originToCenter._x) + (originToCenter._z * originToCenter._z) - (_radius * _radius);

    float discriminant = (b * b) - (4.0 * a * c);

    if (discriminant < 0.0)
        return result;

    float t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    float t2 = (-b + sqrt(discriminant)) / (2.0 * a);

    if (t1 > t2)
        std::swap(t1, t2);

    float y_min = _center._y;
    float y_max = _center._y + _height;
    float t_final = -1.0;

    if (_height <= 0.0) {
        y_min = -std::numeric_limits<float>::infinity();
        y_max = std::numeric_limits<float>::infinity();
    }

    float y_hit1 = ray._origin._y + t1 * ray._direction._y;
    if (t1 > 0.001f && y_hit1 >= y_min && y_hit1 <= y_max) {
        t_final = t1;
    } 
    else {
        float y_hit2 = ray._origin._y + t2 * ray._direction._y;
        if (t2 > 0.001f && y_hit2 >= y_min && y_hit2 <= y_max) {
            t_final = t2;
        }
    }

    if (t_final < 0.001f)
        return result;

    result.is_hit = true;
    result.t = t_final;
    result.point = ray._origin + ray._direction * t_final;
    result.normal = Math::Vector3D(result.point._x - _center._x, 0.0, result.point._z - _center._z) / _radius;
    result.color = _color;
    return result;
}

/**
* @brief Get the pivot point of the cylinder
* @return The pivot point of the cylinder
**/
Raytracer::Math::Vector3D Raytracer::Object::Cylinder::pivot() const
{
    return Raytracer::Math::Vector3D(_center._x, _center._y, _center._z);
}