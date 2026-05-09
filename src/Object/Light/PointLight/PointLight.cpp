/*
** EPITECH PROJECT, 2026
** Project
** File description:
** PointLight
*/

#include "PointLight.hpp"

/**
* @brief Construct a new Light object with default position at the origin, white color, and intensity of 1.0
* @return A new Light object
**/
Raytracer::Object::PointLight::PointLight() : _position(0.0f, 0.0f, 0.0f), _color(255, 255, 255), _intensity(1.0f)
{
}

/**
* @brief Construct a new Light object with the specified position and color, and default intensity of 1.0
* @param position The position of the light
* @param color The color of the light
* @return A new Light object
**/
Raytracer::Object::PointLight::PointLight(const Math::Point3D &position, const Math::Vector3D &color) : _position(position), _color(color), _intensity(1.0f)
{
}

/**
* @brief Construct a new Light object with the specified position, color, and intensity
* @param position The position of the light
* @param color The color of the light
* @param intensity The intensity of the light
* @return A new Light object
**/
Raytracer::Object::PointLight::PointLight(const Math::Point3D &position, const Math::Vector3D &color, const float intensity) : _position(position), _color(color), _intensity(intensity)
{
}

/**
* @brief Get the position of the light
* @return The position of the light
**/
const Raytracer::Math::Point3D &Raytracer::Object::PointLight::position() const
{
	return _position;
}

/**
* @brief Get the color of the light
* @return The color of the light
**/
const Raytracer::Math::Vector3D &Raytracer::Object::PointLight::color() const
{
	return _color;
}

/**
* @brief Get the intensity of the light
* @return The intensity of the light
**/
float Raytracer::Object::PointLight::intensity() const
{
	return _intensity;
}

/**
* @brief Get the direction from a hit point to the light source
* @param hit_point The point where the ray hit an object
* @return The normalized direction vector from the hit point to the light source
**/
Raytracer::Math::Vector3D Raytracer::Object::PointLight::getDirectionToLight(const Math::Point3D &hit_point) const
{
	Math::Vector3D direction = _position - hit_point;

	return direction / direction.length();
}

/**
* @brief Get the distance from a hit point to the light source
* @param hit_point The point where the ray hit an object
* @return The distance from the hit point to the light source
**/
float Raytracer::Object::PointLight::getDistanceToLight(const Math::Point3D &hit_point) const
{
	Math::Vector3D direction = _position - hit_point;

	return direction.length();
}
