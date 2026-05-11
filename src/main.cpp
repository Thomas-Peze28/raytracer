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

    core._ambient_factor = scene._ambient_factor;
    core._diffuse_factor = scene._diffuse_factor;

    return core.run(scene);
}
