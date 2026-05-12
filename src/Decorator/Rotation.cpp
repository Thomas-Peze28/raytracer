/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Rotation
*/

#include "Rotation.hpp"

Raytracer::Object::Rotation::Rotation(std::unique_ptr<IPrimitive> object, const Math::Vector3D &angles)
    : _object(std::move(object)), _angles(angles)
{
}

/**
* @brief Check if a ray hits the rotated object
* @param ray The ray to check
* @return The hit result
**/
Raytracer::HitResult Raytracer::Object::Rotation::hit(const Ray &ray) const
{
   // TODO
}

/**
* @brief Rotate a vector by the specified angles
* @param v The vector to rotate
* @param angleX The rotation angle around the X-axis in degrees
* @param angleY The rotation angle around the Y-axis in degrees
* @param angleZ The rotation angle around the Z-axis in degrees
* @return The rotated vector
**/
Raytracer::Math::Vector3D Raytracer::Object::Rotation::rotate(const Math::Vector3D &v, double angleX, double angleY, double angleZ) const
{
    // TODO
}

/**
* @brief Rotate a point by the specified angles
* @param p The point to rotate
* @param angleX The rotation angle around the X-axis in degrees
* @param angleY The rotation angle around the Y-axis in degrees
* @param angleZ The rotation angle around the Z-axis in degrees
* @return The rotated point
**/
Raytracer::Math::Point3D Raytracer::Object::Rotation::rotate(const Math::Point3D &p, double angleX, double angleY, double angleZ) const
{
    // TODO
}