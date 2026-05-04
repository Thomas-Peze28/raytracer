/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Raytracer
*/

#include "Core.hpp"

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

void Raytracer::Core::write_color(Raytracer::Math::Vector3D color) const
{
    int r = color._x;
    int g = color._y;
    int b = color._z;

    std::cout << r << " " << g << " " << b << std::endl;
}

Raytracer::Math::Vector3D Raytracer::Core::compute_lambert_lighting(const Raytracer::HitResult &hit, const Raytracer::Object::Light &light) const
{
    Raytracer::Math::Vector3D light_dir = light.position() - hit.point;
    light_dir = light_dir / light_dir.length();

    Raytracer::Math::Vector3D normal = hit.normal / hit.normal.length();

    float dot_product = normal.dot(light_dir);
    float lambert_factor = std::max(0.0f, dot_product);

    return hit.color * (lambert_factor * light.intensity());
}

int Raytracer::Core::run(Raytracer::Scene &scene)
{
    std::cout << "P3\n" << scene.camera.width() << " " << scene.camera.height() << "\n255\n";

        for (unsigned int j = 0; j < scene.camera.height(); j++) {
            for (unsigned int i = 0; i < scene.camera.width(); i++) {
            double u = double(i) / double(scene.camera.width());
            double v = double(j) / double(scene.camera.height());
            
            Raytracer::Object::Ray r = scene.camera.ray(u, v);
    
            bool has_hit = false;
            double closest_t = 0.0;
            Raytracer::HitResult closest_hit;
            Math::Vector3D pixel_color(0, 0, 0); 
        
            for (const auto &object : scene.objects) {
                Raytracer::HitResult hit_result = object->hit(r);
                if (hit_result.is_hit && (!has_hit || hit_result.t < closest_t)) {
                    has_hit = true;
                    closest_t = hit_result.t;
                    closest_hit = hit_result;
                }
            }

            if (has_hit && !scene.lights.empty()) {
                pixel_color = compute_lambert_lighting(closest_hit, scene.lights[0]);
            }
            write_color(pixel_color);
        }
    }
    return 0;
}