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
 * @return A new Sphere object
*/
Raytracer::Object::Sphere::Sphere(const Raytracer::Math::Point3D &center, double radius) : _center(center), _radius(radius)
{
}

/**
 * @brief Construct a new Sphere object by copying another Sphere object
 * @param other The other sphere
 * @return A new Sphere object
*/
Raytracer::Object::Sphere::Sphere(const Raytracer::Object::Sphere &other) : _center(other._center), _radius(other._radius)
{
}

/**
 * @brief Check if a ray hits the sphere
 * @param ray The ray to check
 * @return True if the ray hits the sphere, false otherwise
 */
bool Raytracer::Object::Sphere::hit(const Raytracer::Object::Ray &ray) const
{
    Raytracer::Math::Vector3D originToCenter = ray._origin - _center;

    double a = ray._direction.dot(ray._direction);
    if (a <= 0.0)
        return false;

    double b = 2.0 * originToCenter.dot(ray._direction);
    double c = originToCenter.dot(originToCenter) - (_radius * _radius);
    
    double discriminant = b * b - 4 * a * c;

    bool is_hit = (discriminant >= 0);
    return is_hit;
}