/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Parser
*/

#pragma once

    #include <string>
    #include <filesystem>
    #include <libconfig.h++>

    #include "RTCError.hpp"

    #include "Scene.hpp"
    #include "PrimitiveFactory.hpp"
    #include "LightFactory.hpp"

namespace Raytracer
{
    class Parser
    {
        public:
            Parser() = default;
            ~Parser() = default;

            void loadScene(const std::string &filepath, Scene &scene);
            void loadLights(const libconfig::Setting &lightsSetting, Scene &scene);
            void loadPrimitives(const libconfig::Setting &primitivesSetting, Scene &scene);
    };
};