/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Sphere
*/

#include "Sphere.hpp"

/** 
* @brief Construct a new Sphere object
* @param center The center of the sphere
* @param radius The radius of the sphere
* @return A new Sphere object with red default color
**/
Raytracer::Object::Sphere::Sphere(const Math::Point3D &center, double radius) : _center(center), _radius(radius), _color(255, 0, 0)
{
}

/** 
* @brief Construct a new Sphere object
* @param center The center of the sphere
* @param radius The radius of the sphere
* @param color The color of the sphere
* @return A new Sphere object with the specified color
**/
Raytracer::Object::Sphere::Sphere(const Math::Point3D &center, double radius, const Math::Vector3D &color) : _center(center), _radius(radius), _color(color)
{
}

/**
* @brief Construct a new Sphere object by copying another Sphere object
* @param other The other sphere
* @return A new Sphere object
**/
Raytracer::Object::Sphere::Sphere(const Sphere &other) : _center(other._center), _radius(other._radius), _color(other._color)
{
}

/**
* @brief Assign the values of another Sphere object to this Sphere object
* @param other The other sphere
* @return A reference to this Sphere object
**/
Raytracer::Object::Sphere& Raytracer::Object::Sphere::operator=(const Sphere &other)
{
    if (this != &other) {
        _center = other._center;
        _radius = other._radius;
        _color = other._color;
    }
    return *this;
}

/**
* @brief Check if a ray hits the sphere
* @param ray The ray to check
* @return The hit result containing whether the ray hits the sphere, the distance to the hit point, the hit point itself, and the normal at the hit point
**/
Raytracer::HitResult Raytracer::Object::Sphere::hit(const Ray &ray) const
{
    HitResult result;
    Math::Vector3D originToCenter = ray._origin - _center;

    double a = ray._direction.dot(ray._direction);
    if (a <= 0.0)
        return {false, 0.0, Math::Point3D(), Math::Vector3D(), Math::Vector3D()};

    double b = 2.0 * originToCenter.dot(ray._direction);
    double c = originToCenter.dot(originToCenter) - (_radius * _radius);
    
    double discriminant = b * b - 4 * a * c;

    bool is_hit = (discriminant >= 0);

    if (is_hit) {
        double sqrt_discriminant = sqrt(discriminant);
        double t1 = (-b - sqrt_discriminant) / (2.0 * a);
        double t2 = (-b + sqrt_discriminant) / (2.0 * a);

        if (t1 > 0) {
            result.is_hit = true;
            result.t = t1;
            result.point = ray._origin + ray._direction * t1;
            result.normal = (result.point - _center) / _radius;
            result.color = _color;
        } else if (t2 > 0) {
            result.is_hit = true;
            result.t = t2;
            result.point = ray._origin + ray._direction * t2;
            result.normal = (result.point - _center) / _radius;
            result.color = _color;
        } else {
            result.is_hit = false;
        }
    } else {
        result.is_hit = false;
    }
    return result;
}

/**
* @brief Get the pivot point of the sphere
* @return The pivot point of the sphere
**/
Raytracer::Math::Vector3D Raytracer::Object::Sphere::pivot() const
{
    return Raytracer::Math::Vector3D(_center._x, _center._y, _center._z);
}