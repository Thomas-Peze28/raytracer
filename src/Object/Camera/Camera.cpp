/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Camera
*/

#include "Camera.hpp"

Raytracer::Object::Camera::Camera() :
    _origin(Math::Point3D(0.0f, 0.0f, 0.0f)),
    _screen(
        Rectangle3D(
            Math::Point3D(-1.0f, -1.0f, -1.0f),
            Math::Vector3D(2.0f, 0.0f, 0.0f),
            Math::Vector3D(0.0f, 2.0f, 0.0f)
        )
    )
{
}

/** 
* @brief Construct a new Camera object
* @param origin The origin point of the camera
* @param screen The screen rectangle representing the camera's view plane
* @return A new Camera object
*/
Raytracer::Object::Camera::Camera(Math::Point3D origin, Rectangle3D screen) :
    _origin(origin),
    _screen(screen)
{
}

/**
 * @brief Construct a new Camera object by copying another Camera object
 * @param other The other camera
 * @return A new Camera object
*/
Raytracer::Object::Camera::Camera(const Camera &other) :
    _origin(other._origin),
    _screen(other._screen)
{
}

/**
 * @brief Get a ray from the camera through a point on the screen given the parameters u and v
 * @param u The parameter along the bottom side of the screen
 * @param v The parameter along the left side of the screen
 * @return A ray from the camera through the point on the screen corresponding to the parameters u and v
*/
Raytracer::Object::Ray Raytracer::Object::Camera::ray(double u, double v) const
{
    Math::Point3D screen_point = _screen.pointAt(u, v);
    Math::Vector3D ray_direction = screen_point - _origin;

    return Raytracer::Object::Ray(_origin, ray_direction);
}
