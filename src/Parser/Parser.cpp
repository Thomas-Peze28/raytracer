/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Parser
*/

#include "Parser.hpp"
#include <iostream>

/**
* @brief Load light sources from a configuration setting and populate the scene.
* @param lightsSetting The configuration setting containing light source definitions.
* @param scene The scene to populate with the loaded light sources.
**/
void Raytracer::Parser::loadLights(const libconfig::Setting &lightsSetting, Scene &scene)
{
    LightFactory lightFactory;

    if (lightsSetting.exists("ambient")) {
        const float ambient = lightsSetting.lookup("ambient");
        scene._ambient_factor = ambient;
    }
    if (lightsSetting.exists("diffuse")) {
        const float diffuse = lightsSetting.lookup("diffuse");
        scene._diffuse_factor = diffuse;
    }

    if (lightsSetting.exists("directional")) {
        const libconfig::Setting &directionalLights = lightsSetting.lookup("directional");
        for (int i = 0; i < directionalLights.getLength(); ++i) {
            auto light = lightFactory.createLight("directional", directionalLights[i]);
            if (light)
                scene.lights.push_back(std::move(light));
        }
    }

    if (lightsSetting.exists("point")) {
        const libconfig::Setting &pointLights = lightsSetting.lookup("point");
        for (int i = 0; i < pointLights.getLength(); ++i) {
            auto light = lightFactory.createLight("point", pointLights[i]);
            if (light)
                scene.lights.push_back(std::move(light));
        }
    }
}

/**
* @brief Load primitive objects from a configuration setting and populate the scene.
* @param primitivesSetting The configuration setting containing primitive object definitions.
* @param scene The scene to populate with the loaded primitive objects.
**/
void Raytracer::Parser::loadPrimitives(const libconfig::Setting &primitivesSetting, Scene &scene)
{
    PrimitiveFactory primitiveFactory;

    if (primitivesSetting.exists("spheres")) {
        const libconfig::Setting &spheres = primitivesSetting.lookup("spheres");
        for (int i = 0; i < spheres.getLength(); ++i) {
            auto obj = primitiveFactory.createPrimitive("sphere", spheres[i]);
            if (obj)
                scene.objects.push_back(std::move(obj));
        }
    }

    if (primitivesSetting.exists("planes")) {
        const libconfig::Setting &planes = primitivesSetting.lookup("planes");
        for (int i = 0; i < planes.getLength(); ++i) {
            auto obj = primitiveFactory.createPrimitive("plane", planes[i]);
            if (obj)
                scene.objects.push_back(std::move(obj));
        }
    }

    if (primitivesSetting.exists("cylinders")) {
        const libconfig::Setting &cylinders = primitivesSetting.lookup("cylinders");
        for (int i = 0; i < cylinders.getLength(); ++i) {
            auto obj = primitiveFactory.createPrimitive("cylinder", cylinders[i]);
            if (obj)
                scene.objects.push_back(std::move(obj));
        }
    }

    if (primitivesSetting.exists("cones")) {
        const libconfig::Setting &cones = primitivesSetting.lookup("cones");
        for (int i = 0; i < cones.getLength(); ++i) {
            auto obj = primitiveFactory.createPrimitive("cone", cones[i]);
            if (obj)
                scene.objects.push_back(std::move(obj));
        }
    }
}

/**
* @brief Load a scene from a configuration file and populate the provided Scene object.
* @param filepath The path to the configuration file containing the scene description.
* @param scene The Scene object to populate with the loaded scene data.
**/
void Raytracer::Parser::loadScene(const std::string &filepath, Scene &scene)
{
    libconfig::Config config;
    PrimitiveFactory primitiveFactory;
    LightFactory lightFactory;

    try {

        if (filepath.length() < 4 || filepath.substr(filepath.length() - 4) != ".rtx") {
            throw ErrorMajor("Invalid file extension for scene file (must be .rtx): " + filepath);
        }

        config.readFile(filepath.c_str());

        if (config.exists("camera")) {
            const libconfig::Setting &cameraSetting = config.lookup("camera");
            
            int width = cameraSetting.lookup("resolution.width");
            int height = cameraSetting.lookup("resolution.height");
            float fov = 60.0f;
            int samples_per_pixel = 50;

            Math::Point3D lookFrom(0.0f, 0.0f, 0.0f);
            Math::Point3D lookAt(0.0f, 0.0f, -1.0f);
            Math::Vector3D up(0.0f, 1.0f, 0.0f);

            if (cameraSetting.exists("position")) {
                lookFrom = Math::Point3D(
                    cameraSetting.lookup("position.x"),
                    cameraSetting.lookup("position.y"),
                    cameraSetting.lookup("position.z")
                );
            }

            if (cameraSetting.exists("target")) {
                lookAt = Math::Point3D(
                    cameraSetting.lookup("target.x"),
                    cameraSetting.lookup("target.y"),
                    cameraSetting.lookup("target.z")
                );
            }

            if (cameraSetting.exists("up")) {
                up = Math::Vector3D(
                    cameraSetting.lookup("up.x"),
                    cameraSetting.lookup("up.y"),
                    cameraSetting.lookup("up.z")
                );
            }

            cameraSetting.lookupValue("fov", fov);
            cameraSetting.lookupValue("spp", samples_per_pixel);
            scene._samples_per_pixel = samples_per_pixel;
            scene.camera = Object::Camera(width, height, fov, lookFrom, lookAt, up);
        }

        if (config.exists("lights")) {
            loadLights(config.lookup("lights"), scene);
        }

        if (config.exists("primitives")) {
            loadPrimitives(config.lookup("primitives"), scene);
        }
    
    } catch (const libconfig::FileIOException &fioex) {
        throw ErrorMajor("I/O error while reading file: " + filepath);
    } catch (const libconfig::ParseException &pex) {
        throw ErrorMajor("Parse error at " + std::string(pex.getFile()) + ":" + std::to_string(pex.getLine()) + " - " + pex.getError());
    } catch (const std::exception &ex) {
        throw ErrorMajor("Error loading scene: " + std::string(ex.what()));
    } 
}