/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

Raytracer::Math::Vector3D::Vector3D() : _x(0), _y(0), _z(0)
{
}

Raytracer::Math::Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{
}

Raytracer::Math::Vector3D::~Vector3D()
{
}

float Raytracer::Math::Vector3D::length() const
{
    return sqrt((_x * _x) + (_y * _y) + (_z * _z));
}

float Raytracer::Math::Vector3D::dot(Vector3D v1) const
{
    return (_x * v1._x + _y * v1._y + _z * v1._z);
}