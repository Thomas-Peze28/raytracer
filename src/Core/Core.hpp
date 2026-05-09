/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Raytracer
*/

#pragma once

    #include <cstdlib>
    #include <string>
    #include <iostream>

    #include "RTCError.hpp"
    #include "Parser.hpp"
    
    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "Camera.hpp"
    #include "Scene.hpp"
    #include "Sphere.hpp"
    #include "Rectangle3D.hpp"
    #include "IPrimitive.hpp"
    #include "ILight.hpp"
    #include "PointLight.hpp"
    #include "DirectionalLight.hpp"
    #include "Plane.hpp"

namespace Raytracer
{
    class Core
    {
        public:
            Core() = default;
            ~Core() = default;

            int run(Scene &scene);
            void write_color(Math::Vector3D color) const;

            bool displayHelp(int argc, char *argv[]);
            
            void parseSceneFile(const std::string &scene_file) { return _parser.parseSceneFile(scene_file); };

            Raytracer::Math::Vector3D ray_color(const Raytracer::Object::Ray &ray, const Raytracer::Scene &scene) const;

            float _ambient_factor = 0.15f;
            float _diffuse_factor = 1.0f;

        private:
            Parser _parser;

            Raytracer::Math::Vector3D compute_lambert_lighting(const Raytracer::HitResult &hit, const Raytracer::Object::ILight &light) const;
    };
};

