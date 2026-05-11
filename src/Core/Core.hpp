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
    #include <csignal>

    #include "RTCError.hpp"
    
    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Ray.hpp"
    #include "Camera.hpp"
    #include "Scene.hpp"
    #include "IPrimitive.hpp"
    #include "PrimitiveFactory.hpp"
    #include "ILight.hpp"
    #include "LightFactory.hpp"
    #include "Parser.hpp"

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
            
            void loadScene(const std::string &scene_file, Scene &scene) { _parser.loadScene(scene_file, scene); };

            Raytracer::Math::Vector3D ray_color(const Raytracer::Object::Ray &ray, const Raytracer::Scene &scene) const;

            float _ambient_factor;
            float _diffuse_factor;

            static void signalHandler(int signal);
            static bool _signal;

        private:
            Parser _parser;

            Raytracer::Math::Vector3D compute_lambert_lighting(const Raytracer::HitResult &hit, const Raytracer::Object::ILight &light) const;
    };
};

