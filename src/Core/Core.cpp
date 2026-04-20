/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Raytracer
*/

#include "Core.hpp"

Raytracer::Core::Core()
{
}

Raytracer::Core::~Core()
{
}

bool Raytracer::Core::displayHelp(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        return true;
    }
    for (unsigned int i = 0; argv[i] != NULL; i++)
        if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help") {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
            std::cout << "  SCENE_FILE: scene configuration" << std::endl;
            return true;
        }
    return false;
}