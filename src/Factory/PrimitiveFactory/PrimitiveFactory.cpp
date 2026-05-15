/*
** EPITECH PROJECT, 2026
** Raytracer
** File description:
** PrimitiveFactory
*/

#include "PrimitiveFactory.hpp"

/** 
* @brief Construct a new Primitive Factory
**/
Raytracer::PrimitiveFactory::PrimitiveFactory()
{
    _creators["sphere"] = [this](const libconfig::Setting &setting) {
        return createSphere(setting);
    };
    _creators["plane"] = [this](const libconfig::Setting &setting) {
        return createPlane(setting);
    };
    _creators["cylinder"] = [this](const libconfig::Setting &setting) {
        return createCylinder(setting);
    };
    _creators["cone"] = [this](const libconfig::Setting &setting) {
        return createCone(setting);
    };
}

/** 
* @brief Create a new primitive instance based on its type
* @param type The type of the primitive to create
* @return A unique pointer to the created primitive
**/
std::unique_ptr<Raytracer::Object::IPrimitive> Raytracer::PrimitiveFactory::createPrimitive(const std::string &type, const libconfig::Setting &setting) const
{
    auto it = _creators.find(type);
    if (it != _creators.end()) {
        return it->second(setting);
    }
    throw ErrorMajor("Unknown primitive type: " + type);
}

/** 
* @brief Create a new sphere instance
* @param settings The configuration settings for the sphere
* @return A unique pointer to the created sphere
**/
std::unique_ptr<Raytracer::Object::IPrimitive> Raytracer::PrimitiveFactory::createSphere(const libconfig::Setting &settings) const
{
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");
    double r = settings.lookup("r");

    int cr = 255;
    int cg = 255;
    int cb = 255;
    if (settings.exists("color")) {
        cr = settings.lookup("color.r");
        cg = settings.lookup("color.g");
        cb = settings.lookup("color.b");
    }

    std::unique_ptr<Object::IPrimitive> sphere = std::make_unique<Object::Sphere>(
        Math::Point3D(x, y, z), 
        r, 
        Math::Vector3D(cr, cg, cb)
    );

    if (settings.exists("translation")) {
        const libconfig::Setting &t = settings.lookup("translation");
        double tx = t.lookup("x");
        double ty = t.lookup("y");
        double tz = t.lookup("z");
        Math::Vector3D offset(tx, ty, tz);
        sphere = std::make_unique<Object::Translation>(std::move(sphere), offset);
    }

    if (settings.exists("rotation")) {
        const libconfig::Setting &r = settings.lookup("rotation");
        double angleX = r.lookup("x");
        double angleY = r.lookup("y");
        double angleZ = r.lookup("z");
        Math::Vector3D angles(angleX, angleY, angleZ);
        sphere = std::make_unique<Object::Rotation>(std::move(sphere), angles);
    }

    if (settings.exists("scale")) {
        const libconfig::Setting &s = settings.lookup("scale");
        double scaleX = s.lookup("x");
        double scaleY = s.lookup("y");
        double scaleZ = s.lookup("z");
        Math::Vector3D factors(scaleX, scaleY, scaleZ);
        sphere = std::make_unique<Object::Scale>(std::move(sphere), factors);
    }
    
    return sphere;
}

/** 
* @brief Create a new plane instance
* @param settings The configuration settings for the plane
* @return A unique pointer to the created plane
**/
std::unique_ptr<Raytracer::Object::IPrimitive> Raytracer::PrimitiveFactory::createPlane(const libconfig::Setting &settings) const
{
    std::string axis_str = settings.lookup("axis");
    double position = settings.lookup("position");

    int cr = 255;
    int cg = 255;
    int cb = 255;
    if (settings.exists("color")) {
        cr = settings.lookup("color.r");
        cg = settings.lookup("color.g");
        cb = settings.lookup("color.b");
    }

    std::unique_ptr<Object::IPrimitive> plane = std::make_unique<Object::Plane>(
        axis_str[0], 
        position, 
        Math::Vector3D(cr, cg, cb)
    );

    if (settings.exists("translation")) {
        const libconfig::Setting &t = settings.lookup("translation");
        double tx = t.lookup("x");
        double ty = t.lookup("y");
        double tz = t.lookup("z");
        Math::Vector3D offset(tx, ty, tz);
        plane = std::make_unique<Object::Translation>(std::move(plane), offset);
    }

    if (settings.exists("rotation")) {
        const libconfig::Setting &r = settings.lookup("rotation");
        double angleX = r.lookup("x");
        double angleY = r.lookup("y");
        double angleZ = r.lookup("z");
        Math::Vector3D angles(angleX, angleY, angleZ);
        plane = std::make_unique<Object::Rotation>(std::move(plane), angles);
    }

    if (settings.exists("scale")) {
        const libconfig::Setting &s = settings.lookup("scale");
        double scaleX = s.lookup("x");
        double scaleY = s.lookup("y");
        double scaleZ = s.lookup("z");
        Math::Vector3D factors(scaleX, scaleY, scaleZ);
        plane = std::make_unique<Object::Scale>(std::move(plane), factors);
    }

    return plane;
}

/** 
* @brief Create a new cylinder instance
* @param settings The configuration settings for the cylinder
* @return A unique pointer to the created cylinder
**/
std::unique_ptr<Raytracer::Object::IPrimitive> Raytracer::PrimitiveFactory::createCylinder(const libconfig::Setting &settings) const
{
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");

    double r = settings.lookup("r");
    double h = settings.lookup("h");

    int cr = 255;
    int cg = 255;
    int cb = 255;
    if (settings.exists("color")) {
        cr = settings.lookup("color.r");
        cg = settings.lookup("color.g");
        cb = settings.lookup("color.b");
    }

    std::unique_ptr<Object::IPrimitive> cylinder = std::make_unique<Object::Cylinder>(
        Math::Point3D(x, y, z), 
        r, 
        h, 
        Math::Vector3D(cr, cg, cb)
    );

    if (settings.exists("translation")) {
        const libconfig::Setting &t = settings.lookup("translation");
        double tx = t.lookup("x");
        double ty = t.lookup("y");
        double tz = t.lookup("z");
        Math::Vector3D offset(tx, ty, tz);
        cylinder = std::make_unique<Object::Translation>(std::move(cylinder), offset);
    }

    if (settings.exists("rotation")) {
        const libconfig::Setting &r = settings.lookup("rotation");
        double angleX = r.lookup("x");
        double angleY = r.lookup("y");
        double angleZ = r.lookup("z");
        Math::Vector3D angles(angleX, angleY, angleZ);
        cylinder = std::make_unique<Object::Rotation>(std::move(cylinder), angles);
    }

    if (settings.exists("scale")) {
        const libconfig::Setting &s = settings.lookup("scale");
        double scaleX = s.lookup("x");
        double scaleY = s.lookup("y");
        double scaleZ = s.lookup("z");
        Math::Vector3D factors(scaleX, scaleY, scaleZ);
        cylinder = std::make_unique<Object::Scale>(std::move(cylinder), factors);
    }

    return cylinder;
}

/** 
* @brief Create a new cone instance
* @param settings The configuration settings for the cone
* @return A unique pointer to the created cone
**/
std::unique_ptr<Raytracer::Object::IPrimitive> Raytracer::PrimitiveFactory::createCone(const libconfig::Setting &settings) const
{
    double x = settings.lookup("x");
    double y = settings.lookup("y");
    double z = settings.lookup("z");

    double r = settings.lookup("r");
    double h = settings.lookup("h");

    int cr = 255;
    int cg = 255;
    int cb = 255;
    if (settings.exists("color")) {
        cr = settings.lookup("color.r");
        cg = settings.lookup("color.g");
        cb = settings.lookup("color.b");
    }

    std::unique_ptr<Object::IPrimitive> cone = std::make_unique<Object::Cone>(
        Math::Point3D(x, y, z), 
        r, 
        h, 
        Math::Vector3D(cr, cg, cb)
    );

    if (settings.exists("translation")) {
        const libconfig::Setting &t = settings.lookup("translation");
        double tx = t.lookup("x");
        double ty = t.lookup("y");
        double tz = t.lookup("z");
        Math::Vector3D offset(tx, ty, tz);
        cone = std::make_unique<Object::Translation>(std::move(cone), offset);
    }

    if (settings.exists("rotation")) {
        const libconfig::Setting &r = settings.lookup("rotation");
        double angleX = r.lookup("x");
        double angleY = r.lookup("y");
        double angleZ = r.lookup("z");
        Math::Vector3D angles(angleX, angleY, angleZ);
        cone = std::make_unique<Object::Rotation>(std::move(cone), angles);
    }

    if (settings.exists("scale")) {
        const libconfig::Setting &s = settings.lookup("scale");
        double scaleX = s.lookup("x");
        double scaleY = s.lookup("y");
        double scaleZ = s.lookup("z");
        Math::Vector3D factors(scaleX, scaleY, scaleZ);
        cone = std::make_unique<Object::Scale>(std::move(cone), factors);
    }

    return cone;
}
