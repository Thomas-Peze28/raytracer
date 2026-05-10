/*
** EPITECH PROJECT, 2026
** Project
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

/**
* @brief Construct a new Light object with default position at the origin, white color, and intensity of 1.0
* @return A new Light object
**/
Raytracer::Object::DirectionalLight::DirectionalLight() : _direction(0.0f, 0.0f, 1.0f), _color(255, 255, 255), _intensity(1.0f)
{
}

/**
* @brief Construct a new Light object with the specified position and color, and default intensity of 1.0
* @param position The position of the light
* @param color The color of the light
* @return A new Light object
**/
Raytracer::Object::DirectionalLight::DirectionalLight(const Math::Vector3D &direction, const Math::Vector3D &color) : _direction(direction), _color(color), _intensity(1.0f)
{
}

/**
* @brief Construct a new Light object with the specified position, color, and intensity
* @param position The position of the light
* @param color The color of the light
* @param intensity The intensity of the light
* @return A new Light object
**/
Raytracer::Object::DirectionalLight::DirectionalLight(const Math::Vector3D &direction, const Math::Vector3D &color, const float intensity) : _direction(direction), _color(color), _intensity(intensity)
{
}

/**
* @brief Get the direction of the light
* @return The direction of the light
**/
const Raytracer::Math::Vector3D &Raytracer::Object::DirectionalLight::direction() const
{
	return _direction;
}

/**
* @brief Get the color of the light
* @return The color of the light
**/
const Raytracer::Math::Vector3D &Raytracer::Object::DirectionalLight::color() const
{
	return _color;
}

/**
* @brief Get the intensity of the light
* @return The intensity of the light
**/
float Raytracer::Object::DirectionalLight::intensity() const
{
	return _intensity;
}

/**
* @brief Get the direction from a hit point to the light source
* @param hit_point The point where the ray hit an object
* @return The normalized direction vector from the hit point to the light source
**/
Raytracer::Math::Vector3D Raytracer::Object::DirectionalLight::getDirectionToLight(const Math::Point3D &hit_point) const
{
	(void)hit_point;

	return _direction;
}

/**
* @brief Get the distance from a hit point to the light source
* @param hit_point The point where the ray hit an object
* @return The distance from the hit point to the light source
**/
float Raytracer::Object::DirectionalLight::getDistanceToLight(const Math::Point3D &hit_point) const
{
	(void)hit_point;

	return std::numeric_limits<float>::infinity();
}
