/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Rotation
*/

#include "Rotation.hpp"

Raytracer::Object::Rotation::Rotation(std::unique_ptr<IPrimitive> object, const Math::Vector3D &angles)
    : _object(std::move(object)), _angles(angles), _pivot(_object->pivot()._x, _object->pivot()._y, _object->pivot()._z)
{
}

/**
* @brief Check if a ray hits the rotated object
* @param ray The ray to check
* @return The hit result
**/
Raytracer::HitResult Raytracer::Object::Rotation::hit(const Ray &ray) const
{
    Ray rotated_ray;

    Math::Point3D local_origin(
        ray._origin._x - _pivot._x, 
        ray._origin._y - _pivot._y, 
        ray._origin._z - _pivot._z
    );
    
    Math::Point3D rotated_local_origin = rotate(local_origin, -_angles._x, -_angles._y, -_angles._z);
    
    rotated_ray._origin = Math::Point3D(
        rotated_local_origin._x + _pivot._x, 
        rotated_local_origin._y + _pivot._y, 
        rotated_local_origin._z + _pivot._z
    );

    rotated_ray._direction = rotate(ray._direction, -_angles._x, -_angles._y, -_angles._z);

    HitResult hit_result = _object->hit(rotated_ray);

    if (hit_result.is_hit) {
        
        Math::Point3D local_hit(
            hit_result.point._x - _pivot._x, 
            hit_result.point._y - _pivot._y, 
            hit_result.point._z - _pivot._z
        );
        
        Math::Point3D rotated_local_hit = rotate(local_hit, _angles._x, _angles._y, _angles._z);
        
        hit_result.point = Math::Point3D(
            rotated_local_hit._x + _pivot._x, 
            rotated_local_hit._y + _pivot._y, 
            rotated_local_hit._z + _pivot._z
        );
        hit_result.normal = rotate(hit_result.normal, _angles._x, _angles._y, _angles._z);
    }
    return hit_result;
}

/**
* @brief Rotate a vector by the specified angles
* @param vector The vector to rotate
* @param angleX The rotation angle around the X-axis in degrees
* @param angleY The rotation angle around the Y-axis in degrees
* @param angleZ The rotation angle around the Z-axis in degrees
* @return The rotated vector
**/
Raytracer::Math::Vector3D Raytracer::Object::Rotation::rotate(const Math::Vector3D &vector, double angleX, double angleY, double angleZ) const
{
    double radX = angleX * M_PI / 180.0;
    double radY = angleY * M_PI / 180.0;
    double radZ = angleZ * M_PI / 180.0;

    Math::Vector3D result = vector;

    double cosX = std::cos(radX);
    double sinX = std::sin(radX);
    double y1 = result._y * cosX - result._z * sinX;
    double z1 = result._y * sinX + result._z * cosX;
    result._y = y1;
    result._z = z1;

    double cosY = std::cos(radY);
    double sinY = std::sin(radY);
    double x2 = result._x * cosY + result._z * sinY;
    double z2 = -result._x * sinY + result._z * cosY;
    result._x = x2;
    result._z = z2;

    double cosZ = std::cos(radZ);
    double sinZ = std::sin(radZ);
    double x3 = result._x * cosZ - result._y * sinZ;
    double y3 = result._x * sinZ + result._y * cosZ;
    result._x = x3;
    result._y = y3;

    return result;
}

/**
* @brief Rotate a point by the specified angles
* @param point The point to rotate
* @param angleX The rotation angle around the X-axis in degrees
* @param angleY The rotation angle around the Y-axis in degrees
* @param angleZ The rotation angle around the Z-axis in degrees
* @return The rotated point
**/
Raytracer::Math::Point3D Raytracer::Object::Rotation::rotate(const Math::Point3D &point, double angleX, double angleY, double angleZ) const
{
    double radX = angleX * M_PI / 180.0;
    double radY = angleY * M_PI / 180.0;
    double radZ = angleZ * M_PI / 180.0;

    Math::Point3D result = point;

    double cosX = std::cos(radX);
    double sinX = std::sin(radX);
    double y1 = result._y * cosX - result._z * sinX;
    double z1 = result._y * sinX + result._z * cosX;
    result._y = y1;
    result._z = z1;

    double cosY = std::cos(radY);
    double sinY = std::sin(radY);
    double x2 = result._x * cosY + result._z * sinY;
    double z2 = -result._x * sinY + result._z * cosY;
    result._x = x2;
    result._z = z2;

    double cosZ = std::cos(radZ);
    double sinZ = std::sin(radZ);
    double x3 = result._x * cosZ - result._y * sinZ;
    double y3 = result._x * sinZ + result._y * cosZ;
    result._x = x3;
    result._y = y3;

    return result;
}

/**
* @brief Get the pivot point of the rotated object
* @return The pivot point of the rotated object
**/
Raytracer::Math::Vector3D Raytracer::Object::Rotation::pivot() const
{
    return Math::Vector3D(_pivot._x, _pivot._y, _pivot._z);
}