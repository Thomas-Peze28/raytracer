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
    #include <fstream>
    #include <csignal>
    
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
    #include "IProgressObserver.hpp"
    #include "IProgressObservable.hpp"
    #include "ProgressBar.hpp"

namespace Raytracer
{
    class Core : public IProgressObservable
    {
        public:
            Core() = default;
            ~Core() = default;

            std::string getOutputFileName() const { return _output_file_name; }
            void setOutputFileName(const std::string &filename) { _output_file_name = filename; }
        
            int run(Scene &scene);
            void write_color(Math::Vector3D color);
            bool openOutputFile();

            bool displayHelp(int argc, char *argv[]);
            
            void addObserver(IProgressObserver* observer) override;
            void removeObserver(IProgressObserver* observer) override;
            void notifyObservers(unsigned int current, unsigned int total) override;

            void loadScene(const std::string &scene_file, Scene &scene) { _parser.loadScene(scene_file, scene); };

            Raytracer::Math::Vector3D ray_color(const Raytracer::Object::Ray &ray, const Raytracer::Scene &scene) const;

            float _ambient_factor;
            float _diffuse_factor;

            static void signalHandler(int signal);
            static bool _signal;

            int usage(int argc, char *argv[]);

        private:
            std::string _output_file_name;
            std::ofstream _output_file;
            Parser _parser;
            std::vector<IProgressObserver*> _observers;

            Raytracer::Math::Vector3D compute_lambert_lighting(const Raytracer::HitResult &hit, const Raytracer::Object::ILight &light) const;
    };
};

