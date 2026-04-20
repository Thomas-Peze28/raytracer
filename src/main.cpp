/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** main
*/

#include "Core.hpp"

int main(int argc, char *argv[])
{
    Raytracer::Core raytracer;

    if (raytracer.displayHelp(argc, argv))
        return EXIT_SUCCESS;
    try {
        raytracer.parseSceneFile(std::string(argv[1]));
        return EXIT_SUCCESS;
    } catch (const Raytracer::ErrorCritical &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}