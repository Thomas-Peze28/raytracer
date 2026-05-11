#pragma once

#include <map>
#include <string>
#include <functional>
#include <memory>
#include <libconfig.h++>

#include "RTCError.hpp"
#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cylinder.hpp"
#include "Cone.hpp"

namespace Raytracer {
    class PrimitiveFactory {
        public:
            PrimitiveFactory();
            ~PrimitiveFactory() = default;

            std::unique_ptr<Object::IPrimitive> createPrimitive(const std::string &type, const libconfig::Setting &setting) const;
        
        private:
            std::map<std::string, std::function<std::unique_ptr<Object::IPrimitive>(const libconfig::Setting &)>> _creators;
            
            std::unique_ptr<Object::IPrimitive> createSphere(const libconfig::Setting &setting) const;
            std::unique_ptr<Object::IPrimitive> createPlane(const libconfig::Setting &setting) const;
            std::unique_ptr<Object::IPrimitive> createCylinder(const libconfig::Setting &setting) const;
            std::unique_ptr<Object::IPrimitive> createCone(const libconfig::Setting &setting) const;
    };
}