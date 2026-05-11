/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** LightFactory
*/

#include "LightFactory.hpp"

/** 
* @brief Construct a new Light Factory
**/
Raytracer::LightFactory::LightFactory()
{
    _creators["point"] = [this](const libconfig::Setting &setting) {
        return this->createPointLight(setting);
    };
    _creators["directional"] = [this](const libconfig::Setting &setting) {
        return this->createDirectionalLight(setting);
    };
}

/** 
* @brief Create a new light instance based on its type
* @param type The type of the light to create
* @param setting The configuration setting for the light
* @return A unique pointer to the created light
**/
std::unique_ptr<Raytracer::Object::ILight> Raytracer::LightFactory::createLight(const std::string &type, const libconfig::Setting &setting) const
{
    auto it = _creators.find(type);
    if (it != _creators.end()) {
        return it->second(setting);
    }
    throw std::runtime_error("Unknown light type: " + type);
}

/** 
* @brief Create a new point light instance
* @param settings The configuration settings for the point light
* @return A unique pointer to the created point light
**/
std::unique_ptr<Raytracer::Object::ILight> Raytracer::LightFactory::createPointLight(const libconfig::Setting &settings) const
{
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");

    return std::make_unique<Object::PointLight>(
        Math::Point3D(x, y, z), 
        Math::Vector3D(255, 255, 255), 
        1.0f
    );
}

/** 
* @brief Create a new directional light instance
* @param settings The configuration settings for the directional light
* @return A unique pointer to the created directional light
**/
std::unique_ptr<Raytracer::Object::ILight> Raytracer::LightFactory::createDirectionalLight(const libconfig::Setting &settings) const
{
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");

    return std::make_unique<Object::DirectionalLight>(
        Math::Vector3D(x, y, z), 
        Math::Vector3D(255, 255, 255), 
        1.0f
    );
}
