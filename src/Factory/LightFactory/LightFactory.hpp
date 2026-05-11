/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** LightFactory
*/

#pragma once

#include <map>
#include <string>
#include <functional>
#include <memory>
#include <libconfig.h++>

#include "ILight.hpp"
#include "PointLight.hpp"
#include "DirectionalLight.hpp"

namespace Raytracer {

    class LightFactory {
        public:
            LightFactory();
            ~LightFactory() = default;

            std::unique_ptr<Object::ILight> createLight(const std::string &type, const libconfig::Setting &setting) const;
        
        private:
            std::map<std::string, std::function<std::unique_ptr<Object::ILight>(const libconfig::Setting&)>> _creators;

            std::unique_ptr<Object::ILight> createPointLight(const libconfig::Setting &setting) const;
            std::unique_ptr<Object::ILight> createDirectionalLight(const libconfig::Setting &setting) const;
    };
}