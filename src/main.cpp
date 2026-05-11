/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** main
*/

#include "Core.hpp"

int main(int argc, char *argv[])
{
    (void)argc;

    Raytracer::Scene scene;
    Raytracer::Parser parser;

    parser.loadScene(argv[1], scene);

    Raytracer::Core core;

    return core.run(scene);
}
