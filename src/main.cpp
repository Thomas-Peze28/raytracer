/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** main
*/

#include "Core.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        return 84;
    }

    try {
        Raytracer::Scene scene;
        Raytracer::Parser parser;

        parser.loadScene(argv[1], scene);

        Raytracer::Core core;
        Raytracer::ProgressBar progressBar;

        core._ambient_factor = scene._ambient_factor;
        core._diffuse_factor = scene._diffuse_factor;

        core.addObserver(&progressBar);

        return core.run(scene);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
