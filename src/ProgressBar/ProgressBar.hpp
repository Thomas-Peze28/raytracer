/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** ProgressBar
*/

#pragma once

#include "IProgressObserver.hpp"

namespace Raytracer {

    class ProgressBar : public IProgressObserver {
        public:
            ProgressBar() = default;
            ~ProgressBar() = default;

            void update(unsigned int current, unsigned int total) override;
    };
}