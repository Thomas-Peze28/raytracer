/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** PrimitiveFactory
*/

#pragma once

#include <map>
#include <string>
#include <functional>
#include <memory>

#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cylinder.hpp"
#include "Cone.hpp"

namespace Raytracer {

    class PrimitiveFactory {
        public:
            PrimitiveFactory();
            ~PrimitiveFactory() = default;

            std::unique_ptr<Object::IPrimitive> createPrimitive(const std::string &type) const;
        
        private:
            std::map<std::string, std::function<std::unique_ptr<Object::IPrimitive>()>> _creators;
    };
}