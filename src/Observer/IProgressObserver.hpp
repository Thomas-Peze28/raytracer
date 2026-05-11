/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** IProgressObserver
*/

#pragma once

namespace Raytracer {

    class IProgressObserver {
        public:
            virtual ~IProgressObserver() = default;
            
            virtual void update(unsigned int current, unsigned int total) = 0;
    };
}
