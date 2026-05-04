/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

/**
* @brief Construct a new Vector3D object with default values (0, 0, 0)
* @return A new Vector3D object
**/
Raytracer::Math::Vector3D::Vector3D() : _x(0), _y(0), _z(0)
{
}

/**
* @brief Construct a new Vector3D object
* @param x The x coordinate
* @param y The y coordinate
* @param z The z coordinate
* @return A new Vector3D object
**/
Raytracer::Math::Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{
}

/**
* @brief Construct a new Vector3D object by copying another Vector3D object
* @param other The other vector 3D
* @return A new Vector3D object
**/
Raytracer::Math::Vector3D::Vector3D(const Vector3D &other) : _x(other._x), _y(other._y), _z(other._z)
{
}

/**
* @brief Assign the values of another Vector3D object to this Vector3D object
* @param other The other vector 3D
* @return A reference to this Vector3D object
**/
Raytracer::Math::Vector3D& Raytracer::Math::Vector3D::operator=(const Vector3D &other)
{
    if (this != &other) {
        _x = other._x;
        _y = other._y;
        _z = other._z;
    }
    return *this;
}

/**
* @brief Calculate the length of the vector 3D
* @return The length of the vector 3D
**/
float Raytracer::Math::Vector3D::length() const
{
    return std::sqrt(_x * _x + _y * _y + _z * _z);
}

/**
* @brief Calculate the dot product of two vector 3D
* @param other The other vector 3D
* @return The dot product of the two vectors
**/
float Raytracer::Math::Vector3D::dot(const Vector3D &other) const
{
    return _x * other._x + _y * other._y + _z * other._z;
}

/**
* @brief Add two vector 3D
* @param other The other vector 3D
* @return The sum of the two vectors
**/
Raytracer::Math::Vector3D Raytracer::Math::Vector3D::operator+(const Vector3D &other) const
{
    return Vector3D(_x + other._x, _y + other._y, _z + other._z);
}

/**
* @brief Add a vector 3D to this vector 3D
* @param other The other vector 3D
* @return A reference to this vector 3D
**/
Raytracer::Math::Vector3D &Raytracer::Math::Vector3D::operator+=(const Vector3D &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

/**
* @brief Subtract two vector 3D
* @param other The other vector 3D
* @return The difference of the two vectors
**/
Raytracer::Math::Vector3D Raytracer::Math::Vector3D::operator-(const Vector3D &other) const
{
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}

/**
* @brief Subtract a vector 3D from this vector 3D
* @param other The other vector 3D
* @return A reference to this vector 3D
**/
Raytracer::Math::Vector3D &Raytracer::Math::Vector3D::operator-=(const Vector3D &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

/**
* @brief Multiply two vector 3D
* @param other The other vector 3D
* @return The product of the two vectors
**/
Raytracer::Math::Vector3D Raytracer::Math::Vector3D::operator*(const Vector3D &other) const
{
    return Vector3D(_x * other._x, _y * other._y, _z * other._z);
}

/**
* @brief Multiply this vector 3D by another vector 3D
* @param other The other vector 3D
* @return A reference to this vector 3D
**/
Raytracer::Math::Vector3D &Raytracer::Math::Vector3D::operator*=(const Vector3D &other)
{
    _x *= other._x;
    _y *= other._y;
    _z *= other._z;
    return *this;
}

/**
* @brief Divide two vector 3D
* @param other The other vector 3D
* @return The quotient of the two vectors
**/
Raytracer::Math::Vector3D Raytracer::Math::Vector3D::operator/(const Vector3D &other) const
{
    return Vector3D(_x / other._x, _y / other._y, _z / other._z);
}

/**
* @brief Divide this vector 3D by another vector 3D
* @param other The other vector 3D
* @return A reference to this vector 3D
**/
Raytracer::Math::Vector3D &Raytracer::Math::Vector3D::operator/=(const Vector3D &other)
{
    _x /= other._x;
    _y /= other._y;
    _z /= other._z;
    return *this;
}

/**
* @brief Multiply this vector 3D by a scalar
* @param scalar The scalar
* @return The product of the vector and the scalar
**/
Raytracer::Math::Vector3D Raytracer::Math::Vector3D::operator*(float scalar) const
{
    return Vector3D(_x * scalar, _y * scalar, _z * scalar);
}

/**
* @brief Multiply this vector 3D by a scalar
* @param scalar The scalar
* @return A reference to this vector 3D
**/
Raytracer::Math::Vector3D &Raytracer::Math::Vector3D::operator*=(float scalar)
{
    _x *= scalar;
    _y *= scalar;
    _z *= scalar;
    return *this;
}

/**
* @brief Divide this vector 3D by a scalar
* @param scalar The scalar
* @return The quotient of the vector and the scalar
**/
Raytracer::Math::Vector3D Raytracer::Math::Vector3D::operator/(double scalar) const
{
    return Vector3D(_x / scalar, _y / scalar, _z / scalar);
}

/**
* @brief Divide this vector 3D by a scalar
* @param scalar The scalar
* @return A reference to this vector 3D
**/
Raytracer::Math::Vector3D &Raytracer::Math::Vector3D::operator/=(double scalar)
{
    _x /= scalar;
    _y /= scalar;
    _z /= scalar;
    return *this;
}