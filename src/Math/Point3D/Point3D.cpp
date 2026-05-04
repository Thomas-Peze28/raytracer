/*
** EPITECH PROJECT, 2026
** Project
** File description:
** Point3D
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"

/**
* @brief Construct a new Point3D object with default values (0, 0, 0)
* @return A new Point3D object
**/
Raytracer::Math::Point3D::Point3D() : _x(0), _y(0), _z(0)
{
}

/**
* @brief Construct a new Point3D object
* @param x The x coordinate
* @param y The y coordinate
* @param z The z coordinate
* @return A new Point3D object
**/
Raytracer::Math::Point3D::Point3D(float x, float y, float z) : _x(x), _y(y), _z(z)
{
}

/**
* @brief Construct a new Point3D object by copying another Point3D object
* @param other The other point 3D
* @return A new Point3D object
**/
Raytracer::Math::Point3D::Point3D(const Point3D &other) : _x(other._x), _y(other._y), _z(other._z)
{
}

/**
* @brief Calculate the vector from this point to another point
* @param other The other point
* @return The vector from this point to the other point
*/
Raytracer::Math::Vector3D Raytracer::Math::Point3D::operator-(const Point3D &other) const
{
	return Math::Vector3D(_x - other._x, _y - other._y, _z - other._z);
}

/**
* @brief Calculate the point resulting from adding a vector to this point
* @param vec The vector to add
* @return The resulting point
*/
Raytracer::Math::Point3D Raytracer::Math::Point3D::operator+(const Vector3D &vec) const
{
	return Math::Point3D(_x + vec._x, _y + vec._y, _z + vec._z);
}

/**
* @brief Calculate the point resulting from subtracting a vector from this point
* @param vec The vector to subtract
* @return The resulting point
*/
Raytracer::Math::Point3D Raytracer::Math::Point3D::operator-(const Vector3D &vec) const
{
	return Math::Point3D(_x - vec._x, _y - vec._y, _z - vec._z);
}

/**
* @brief Assign the values of another Point3D object to this Point3D object
* @param other The other Point3D object
* @return A reference to this Point3D object after assignment
**/
Raytracer::Math::Point3D& Raytracer::Math::Point3D::operator=(const Point3D &other)
{
	if (this != &other) {
		_x = other._x;
		_y = other._y;
		_z = other._z;
	}
	return *this;
}

/**
* @brief Calculate the distance between this point and another point
* @param other The other point
* @return The distance between the two points
*/
float Raytracer::Math::Point3D::distance(const Point3D &other) const
{
	return std::sqrt(std::pow(_x - other._x, 2) + std::pow(_y - other._y, 2) + std::pow(_z - other._z, 2));
}
