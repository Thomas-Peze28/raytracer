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
    (void)argv;

    Raytracer::Core core;

    Raytracer::Scene scene;

    scene.camera = Raytracer::Object::Camera(720, 480);
    scene.lights.push_back(Raytracer::Object::Light(Raytracer::Math::Point3D(-100, -80, 10), Raytracer::Math::Vector3D(255, 255, 255), 0.7f)); // Lumière
    scene.lights.push_back(Raytracer::Object::Light(Raytracer::Math::Point3D(100, 10, 5), Raytracer::Math::Vector3D(255, 255, 255), 0.4f)); // Lumière

    scene.objects.push_back(std::make_unique<Raytracer::Object::Plane>('x', -1.5, Raytracer::Math::Vector3D(255, 255, 255))); // Plane blanc sol
    scene.objects.push_back(std::make_unique<Raytracer::Object::Sphere>(Raytracer::Math::Point3D(1, -1, -5), 1.2, Raytracer::Math::Vector3D(255, 0, 0))); // Sphere rouge
    scene.objects.push_back(std::make_unique<Raytracer::Object::Sphere>(Raytracer::Math::Point3D(0, 0, -5), 1.0, Raytracer::Math::Vector3D(0, 255, 0))); // Sphere verte
    scene.objects.push_back(std::make_unique<Raytracer::Object::Sphere>(Raytracer::Math::Point3D(-2, 1, -5), 1.0, Raytracer::Math::Vector3D(0, 0, 255))); // Sphere bleue
    scene.objects.push_back(std::make_unique<Raytracer::Object::Sphere>(Raytracer::Math::Point3D(2, 0, -5), 1.0, Raytracer::Math::Vector3D(255, 255, 0))); // Sphere jaune

    core._ambient_factor = 0.1f;
    core._diffuse_factor = 1.0f;

    return core.run(scene);

    /*
    if (raytracer.displayHelp(argc, argv))
        return EXIT_SUCCESS;
    try {
        raytracer.parseSceneFile(std::string(argv[1]));
        return EXIT_SUCCESS;
    } catch (const Raytracer::ErrorCritical &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    */
}