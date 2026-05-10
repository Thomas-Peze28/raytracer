/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Scene
*/

#include <vector>
#include <memory>
#include "IPrimitive.hpp"
#include "ILight.hpp"
#include "Camera.hpp"

namespace Raytracer {

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            bool hit(const Raytracer::Object::Ray &ray, float t_min, float t_max, Raytracer::HitResult &closest_hit) const;

            Object::Camera camera;
            std::vector<std::unique_ptr<Object::ILight>> lights;
            std::vector<std::unique_ptr<Object::IPrimitive>> objects;
    };
}