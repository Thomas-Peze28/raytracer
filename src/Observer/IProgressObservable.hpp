/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** IProgressObservable
*/

#pragma once

#include <vector>
#include <algorithm>
#include "IProgressObserver.hpp"

namespace Raytracer {

    class IProgressObservable {
        public:
            virtual ~IProgressObservable() = default;
            
            virtual void addObserver(IProgressObserver* observer) = 0;
            virtual void removeObserver(IProgressObserver* observer) = 0;
            virtual void notifyObservers(unsigned int current, unsigned int total) = 0;
    };
}
