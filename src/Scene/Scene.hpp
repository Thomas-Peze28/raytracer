/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** Scene
*/

#include <vector>
#include <memory>
#include "IPrimitive.hpp"
#include "Light.hpp"
#include "Camera.hpp"

namespace Raytracer {

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            Object::Camera camera;
            std::vector<Object::Light> lights;
            std::vector<std::unique_ptr<Object::IPrimitive>> objects;
    };
}