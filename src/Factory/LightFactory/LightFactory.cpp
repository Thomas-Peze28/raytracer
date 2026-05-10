/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** LightFactory
*/

#include "LightFactory.hpp"

/** 
* @brief Construct a new Light Factory:: Light Factory object
**/
Raytracer::LightFactory::LightFactory()
{
    _creators["point"] = []() { return std::make_unique<Object::PointLight>(); };
    _creators["directional"] = []() { return std::make_unique<Object::DirectionalLight>(); };
}

/** 
* @brief Create a new light instance based on its type
* @param type The type of the light to create
* @return A unique pointer to the created light
**/
std::unique_ptr<Raytracer::Object::ILight> Raytracer::LightFactory::createLight(const std::string &type) const
{
    auto it = _creators.find(type);
    if (it != _creators.end()) {
        return it->second();
    }
    throw std::runtime_error("Unknown light type: " + type);
}
