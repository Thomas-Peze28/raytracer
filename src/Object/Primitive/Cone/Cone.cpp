/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Cone
*/

#include "Cone.hpp"

/** 
 * @brief Construct a new Cone object
 * @param center The center of the cone
 * @param angle The angle of the cone
 * @param height The height of the cone
 * @return A new Cone object with red default color
*/
Raytracer::Object::Cone::Cone(const Math::Point3D &center, double angle, double height) : _center(center), _angle(angle), _height(height), _color(255, 0, 0)
{
}

/** 
 * @brief Construct a new Cone object
 * @param center The center of the cone
 * @param angle The angle of the cone
 * @param height The height of the cone
 * @param color The color of the cone
 * @return A new Cone object with the specified color
*/
Raytracer::Object::Cone::Cone(const Math::Point3D &center, double angle, double height, const Math::Vector3D &color) : _center(center), _angle(angle), _height(height), _color(color)
{
}

/**
 * @brief Construct a new Cone object by copying another Cone object
 * @param other The other cone to copy
 * @return A new Cone object that is a copy of the other cone
*/
Raytracer::Object::Cone::Cone(const Cone &other) : _center(other._center), _angle(other._angle), _height(other._height), _color(other._color)
{
}

/**
* @brief Assign the values of another Cone object to this Cone object
* @param other The other cone
* @return A reference to this Cone object
**/
Raytracer::Object::Cone& Raytracer::Object::Cone::operator=(const Cone &other)
{
    if (this != &other) {
        _center = other._center;
        _angle = other._angle;
        _height = other._height;
        _color = other._color;
    }
    return *this;
}

/**
* @brief Check if a ray hits the cone
* @param ray The ray to check
* @return The hit result containing whether the ray hits the cone, the distance to the hit point, the hit point itself, and the normal at the hit point
**/
Raytracer::HitResult Raytracer::Object::Cone::hit(const Ray &ray) const
{
    HitResult result;
    result.is_hit = false;

    float radians = _angle * (M_PI / 180.0f);
    float k = tan(radians);

    Math::Vector3D originToCenter = ray._origin - _center;

    float a = (ray._direction._x * ray._direction._x) + (ray._direction._z * ray._direction._z) - (k * k * ray._direction._y * ray._direction._y);

    if (a < 0.0f)
        return result;

    float b = 2.0f * ((originToCenter._x * ray._direction._x) + (originToCenter._z * ray._direction._z) - (k * k * originToCenter._y * ray._direction._y));
    float c = (originToCenter._x * originToCenter._x) + (originToCenter._z * originToCenter._z) - (k * k * originToCenter._y * originToCenter._y);
    float discriminant = (b * b) - (4.0f * a * c);

    if (discriminant < 0.0f)
        return result;

    float t1 = (-b - sqrt(discriminant)) / (2.0f * a);
    float t2 = (-b + sqrt(discriminant)) / (2.0f * a);

    if (t1 > t2)
        std::swap(t1, t2);

    float y_min = _center._y;
    float y_max = _center._y + _height;
    float t_final = -1.0f;

    if (_height <= 0.0f) {
        y_min = -std::numeric_limits<float>::infinity();
        y_max = std::numeric_limits<float>::infinity();
    }

    float y_hit1 = ray._origin._y + t1 * ray._direction._y;
    if (t1 > 0.001f && (y_hit1 >= y_min && y_hit1 <= y_max)) {
        t_final = t1;
    } else {
        float y_hit2 = ray._origin._y + t2 * ray._direction._y;
        if (t2 > 0.001f && (y_hit2 >= y_min && y_hit2 <= y_max)) {
            t_final = t2;
        }
    }

    if (t_final < 0.001f)
        return result;

    result.is_hit = true;
    result.t = t_final;
    result.point = ray._origin + ray._direction * t_final;

    float dy = result.point._y - _center._y;
    Math::Vector3D normal(
        result.point._x - _center._x,
        -k * k * dy,
        result.point._z - _center._z
    );
    result.normal = normal / normal.length();

    if (t_final == t2)
        result.normal = result.normal * -1.0f;
    result.color = _color;
    return result;
}

/**
* @brief Get the pivot point of the cone
* @return The pivot point of the cone
**/
Raytracer::Math::Vector3D Raytracer::Object::Cone::pivot() const
{
    return Raytracer::Math::Vector3D(_center._x, _center._y, _center._z);
}