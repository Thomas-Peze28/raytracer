/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** PrimitiveFactory
*/

#include "PrimitiveFactory.hpp"

/** 
* @brief Construct a new Primitive Factory:: Primitive Factory object
**/
Raytracer::PrimitiveFactory::PrimitiveFactory()
{
    _creators["sphere"] = []() { return std::make_unique<Object::Sphere>(); };
    _creators["plane"] = []() { return std::make_unique<Object::Plane>(); };
    _creators["cylinder"] = []() { return std::make_unique<Object::Cylinder>(); };
    _creators["cone"] = []() { return std::make_unique<Object::Cone>(); };
}

/** 
* @brief Create a new primitive instance based on its type
* @param type The type of the primitive to create
* @return A unique pointer to the created primitive
**/
std::unique_ptr<Raytracer::Object::IPrimitive> Raytracer::PrimitiveFactory::createPrimitive(const std::string &type) const
{
    auto it = _creators.find(type);
    if (it != _creators.end()) {
        return it->second();
    }
    throw std::runtime_error("Unknown primitive type: " + type);
}
