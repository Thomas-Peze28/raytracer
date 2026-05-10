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

namespace Raytracer
{
    class Parser
    {
        public:
            Parser();
            ~Parser();

            void parseSceneFile(const std::string &scene_file);
    };
};