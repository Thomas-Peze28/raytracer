/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Camera
*/

#include "Camera.hpp"

Raytracer::Object::Camera::Camera()
{
    _origin = Math::Point3D(0.0f, 0.0f, 0.0f);
    _screen = Rectangle3D(
            Math::Point3D(-1.0f, -1.0f, -1.0f),
            Math::Vector3D(2.0f, 0.0f, 0.0f),
            Math::Vector3D(0.0f, 2.0f, 0.0f)
        );
}

/** 
* @brief Construct a new Camera object
* @param width The width of the camera's view plane
* @param height The height of the camera's view plane
* @return A new Camera object
*/
Raytracer::Object::Camera::Camera(unsigned int width, unsigned int height) {
    _width = width;
    _height = height;

    double aspect_ratio = double(_width) / double(_height);
    double base_width = 2.0f;
    double base_height = base_width / aspect_ratio;  


    _origin = Math::Point3D(0.0f, 0.0f, 0.0f);
    _screen = Rectangle3D(
        Math::Point3D(-base_width / 2.0f, -base_height / 2.0f, -1.0f),
        Math::Vector3D(base_width, 0.0f, 0.0f),
        Math::Vector3D(0.0f, base_height, 0.0f)
    );
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
    return Raytracer::Object::Ray(_origin, _screen.pointAt(u, v) - _origin);
}

/**
 * @brief Assign the values of another Camera object to this Camera object
 * @param other The other camera
 * @return A reference to this Camera object
*/
Raytracer::Object::Camera& Raytracer::Object::Camera::operator=(const Camera &other)
{
    if (this != &other) {
        _origin = other._origin;
        _screen = other._screen;
        _width = other._width;
        _height = other._height;
    }
    return *this;
}

/**
* @brief Get the width of the camera's view plane
* @return The width of the camera's view plane
**/
unsigned int Raytracer::Object::Camera::width() const
{
    return _width;
}

/**
* @brief Get the height of the camera's view plane
* @return The height of the camera's view plane
**/
unsigned int Raytracer::Object::Camera::height() const
{
    return _height;
}