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
    _fov = 90;
    _lookFrom = Math::Point3D(0.0f, 0.0f, 0.0f);
    _lookAt = Math::Point3D(0.0f, 0.0f, -1.0f);
    _up = Math::Vector3D(0.0f, 1.0f, 0.0f);
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
    _fov = 90;
    _lookFrom = Math::Point3D(0.0f, 0.0f, 0.0f);
    _lookAt = Math::Point3D(0.0f, 0.0f, -1.0f);
    _up = Math::Vector3D(0.0f, 1.0f, 0.0f);

    _origin = _lookFrom;

    double theta = _fov * (M_PI / 180.0);
    double h = tan(theta / 2.0);

    double aspect_ratio = double(_width) / double(_height);
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;

    Math::Vector3D w = (_lookFrom - _lookAt).normalized();
    Math::Vector3D u = _up.cross(w).normalized();
    Math::Vector3D v = w.cross(u);

    Math::Point3D lower_left = _origin - (u * (viewport_width / 2.0)) - (v * (viewport_height / 2.0)) - w;

    _screen = Rectangle3D(
        lower_left,
        u * viewport_width,
        v * viewport_height
    );
}

Raytracer::Object::Camera::Camera(unsigned int width, unsigned int height, unsigned int fov) {
    _width = width;
    _height = height;
    _fov = fov;
    _lookFrom = Math::Point3D(0.0f, 0.0f, 0.0f);
    _lookAt = Math::Point3D(0.0f, 0.0f, -1.0f);
    _up = Math::Vector3D(0.0f, 1.0f, 0.0f);

    double theta = _fov * (M_PI / 180.0);
    double h = tan(theta / 2.0);

    double aspect_ratio = double(_width) / double(_height);
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;

    Math::Vector3D w = (_lookFrom - _lookAt).normalized();
    Math::Vector3D u = _up.cross(w).normalized();
    Math::Vector3D v = w.cross(u);

    _origin = _lookFrom;
    Math::Point3D lower_left = _origin - (u * (viewport_width / 2.0)) - (v * (viewport_height / 2.0)) - w;
    _screen = Rectangle3D(
        lower_left,
        u * viewport_width,
        v * viewport_height
    );
}

Raytracer::Object::Camera::Camera(unsigned int width, unsigned int height, unsigned int fov, const Math::Point3D &lookFrom, const Math::Point3D &lookAt, const Math::Vector3D &up) {
    _width = width;
    _height = height;
    _fov = fov;
    _lookFrom = lookFrom;
    _lookAt = lookAt;
    _up = up;

    double theta = _fov * (M_PI / 180.0);
    double h = tan(theta / 2.0);

    double aspect_ratio = double(_width) / double(_height);
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;

    Math::Vector3D w = (_lookFrom - _lookAt).normalized();
    Math::Vector3D u = _up.cross(w).normalized();
    Math::Vector3D v = w.cross(u);

    _origin = lookFrom;
    Math::Point3D lower_left = _origin - (u * (viewport_width / 2.0)) - (v * (viewport_height / 2.0)) - w;
    _screen = Rectangle3D(
        lower_left,
        u * viewport_width,
        v * viewport_height
    );
}

/**
 * @brief Construct a new Camera object by copying another Camera object
 * @param other The other camera
 * @return A new Camera object
*/
Raytracer::Object::Camera::Camera(const Camera &other) :
    _origin(other._origin),
    _screen(other._screen),
    _width(other._width),
    _height(other._height),
    _fov(other._fov),
    _lookFrom(other._lookFrom),
    _lookAt(other._lookAt),
    _up(other._up)
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
        _fov = other._fov;
        _lookFrom = other._lookFrom;
        _lookAt = other._lookAt;
        _up = other._up;
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

/**
* @brief Get the field of view of the camera
* @return The field of view of the camera
**/
unsigned int Raytracer::Object::Camera::fov() const
{
    return _fov;
}

/**
* @brief Get the position of the camera
* @return The position of the camera
**/
Raytracer::Math::Point3D Raytracer::Object::Camera::lookFrom() const
{
    return _lookFrom;
}

/**
* @brief Get the point the camera is looking at
* @return The point the camera is looking at
**/
Raytracer::Math::Point3D Raytracer::Object::Camera::lookAt() const
{
    return _lookAt;
}

/**
* @brief Get the up vector of the camera
* @return The up vector of the camera
**/
Raytracer::Math::Vector3D Raytracer::Object::Camera::up() const
{
    return _up;
}