/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Raytracer
*/

#pragma once

    #include <cstdlib>
    #include <string>
    #include <iostream>

    #include "RTCError.hpp"
    #include "Parser.hpp"

namespace Raytracer
{
    class Core
    {
        public:
            Core();
            ~Core();

            bool displayHelp(int argc, char *argv[]);
            
            void parseSceneFile(const std::string &scene_file) { return _parser.parseSceneFile(scene_file); };

        private:
            Parser _parser;
    };
};

