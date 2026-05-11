/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Raytracer
*/

#include "Core.hpp"

bool Raytracer::Core::_signal = false;

/**
* Displays help information for the raytracer.
* @param argc The number of command-line arguments.
* @param argv The array of command-line arguments.
* @return True if help was displayed, false otherwise.
**/
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

    if (r < 0)
        r = 0;
    if (g < 0)
        g = 0;
    if (b < 0)
        b = 0;
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;

    std::cout << r << " " << g << " " << b << std::endl;
}

/**
* Computes the Lambert lighting for a hit point and a light source.
* @param hit The hit result.
* @param light The light source.
* @return The computed lighting color.
**/
Raytracer::Math::Vector3D Raytracer::Core::compute_lambert_lighting(const Raytracer::HitResult &hit, const Raytracer::Object::ILight &light) const
{
    Math::Vector3D light_dir = light.getDirectionToLight(hit.point);
    Math::Vector3D normal = hit.normal / hit.normal.length();
    Math::Vector3D light_color = light.color() / 255.0;

    float dot_product = normal.dot(light_dir);
    float lambert_factor = std::max(0.0f, dot_product);

    return (hit.color * light_color * (lambert_factor * light.intensity() * _diffuse_factor));
}

/**
* Adds an observer to the list of observers.
* @param observer The observer to add.
**/
void Raytracer::Core::addObserver(Raytracer::IProgressObserver* observer)
{
    _observers.push_back(observer);
}

/**
* Removes an observer from the list of observers.
* @param observer The observer to remove.
**/
void Raytracer::Core::removeObserver(Raytracer::IProgressObserver* observer)
{
    _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
}

/**
* Notifies all observers of a progress update.
* @param current The current progress.
* @param total The total progress.
**/
void Raytracer::Core::notifyObservers(unsigned int current, unsigned int total)
{
    for (auto observer : _observers) {
        observer->update(current, total);
    }
}

/**
* Calculates the color of a ray after it intersects with objects in the scene.
* @param ray The ray to trace.
* @param scene The scene containing objects and lights.
* @return The calculated color for the ray.
**/
Raytracer::Math::Vector3D Raytracer::Core::ray_color(const Raytracer::Object::Ray &ray, const Raytracer::Scene &scene) const
{
    Raytracer::HitResult closest_hit;
    
    if (!scene.hit(ray, 0.00001f, 100000.0f, closest_hit)) {
        return Math::Vector3D(0, 0, 0);
    }

    Math::Vector3D pixel_color = closest_hit.color * _ambient_factor;

    for (const auto &light : scene.lights) {
        Math::Vector3D light_dir = light->getDirectionToLight(closest_hit.point);
        float distance_to_light = light->getDistanceToLight(closest_hit.point);

        if (light_dir.dot(closest_hit.normal) <= 0)
            continue;

        Raytracer::Object::Ray shadow_ray(closest_hit.point + closest_hit.normal * 0.00001f, light_dir);
        Raytracer::HitResult shadow_hit;

        if (!scene.hit(shadow_ray, 0.00001f, distance_to_light, shadow_hit)) {
            pixel_color += compute_lambert_lighting(closest_hit, *light);
        }
    }
    return pixel_color;
}

/**
* Handles the signal for interrupting the raytracer.
* @param signal The signal received.
**/
void Raytracer::Core::signalHandler(int signal)
{
    if (signal == SIGINT) {
        _signal = true;
    }
}

/**
* Runs the raytracer with the given scene.
* @param scene The scene to render.
* @return The result of the rendering process.
**/
int Raytracer::Core::run(Raytracer::Scene &scene)
{
    std::signal(SIGINT, signalHandler);

    std::cout << "P3\n" << scene.camera.width() << " " << scene.camera.height() << "\n255\n";

        for (unsigned int j = 0; j < scene.camera.height(); j++) {

            notifyObservers(j, scene.camera.height());

            for (unsigned int i = 0; i < scene.camera.width(); i++) {

                if (_signal == true) {
                    write_color(Math::Vector3D(0, 0, 0));
                    continue;
                }

                double u = double(i) / double(scene.camera.width());
                double v = double(j) / double(scene.camera.height());

                Raytracer::Object::Ray r = scene.camera.ray(u, v);
                
                Math::Vector3D pixel_color = ray_color(r, scene); 
                write_color(pixel_color);
        }
    }
    return 0;
}