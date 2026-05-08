/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Scene
*/

#include "Scene.hpp"

/**
* Checks if a ray hits any object in the scene and returns the closest hit result.
* @param ray The ray to test for intersection.
* @param t_min The minimum t value for valid hits.
* @param t_max The maximum t value for valid hits.
* @param closest_hit A reference to store the closest hit result.
* @return True if the ray hits an object, false otherwise.
**/
bool Raytracer::Scene::hit(const Raytracer::Object::Ray &ray, float t_min, float t_max, Raytracer::HitResult &closest_hit) const {
    bool has_hit = false;
    double closest_t = t_max;
    
    for (const auto &object : objects) {
        Raytracer::HitResult current_hit = object->hit(ray);
        
        if (current_hit.is_hit && current_hit.t > t_min && current_hit.t < closest_t) {
            has_hit = true;
            closest_t = current_hit.t;
            closest_hit = current_hit;
        }
    }
    return has_hit;
}
