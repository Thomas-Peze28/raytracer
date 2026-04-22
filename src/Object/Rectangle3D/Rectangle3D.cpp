/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

/** 
* @brief Construct a new Rectangle3D object
* @param origin The origin point of the rectangle
* @param bottom_side The vector representing the bottom side of the rectangle
* @param left_side The vector representing the left side of the rectangle
* @return A new Rectangle3D object
*/
Raytracer::Object::Rectangle3D::Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &bottom_side, const Math::Vector3D &left_side) :
    _origin(origin),
    _bottom_side(bottom_side),
    _left_side(left_side)
{
}

/**
 * @brief Construct a new Rectangle3D object by copying another Rectangle3D object
 * @param other The other rectangle
 * @return A new Rectangle3D object
*/
Raytracer::Object::Rectangle3D::Rectangle3D(const Rectangle3D &other) :
    _origin(other._origin),
    _bottom_side(other._bottom_side),
    _left_side(other._left_side)
{
}

/**
 * @brief Get a point on the rectangle given the parameters u and v
 * @param u The parameter along the bottom side of the rectangle (0 to 1)
 * @param v The parameter along the left side of the rectangle (0 to 1)
 * @return A point on the rectangle corresponding to the parameters u and v
*/
Raytracer::Math::Point3D Raytracer::Object::Rectangle3D::pointAt(double u, double v) const
{
    return _origin + _bottom_side * u + _left_side * v;
}
