/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** ProgressBar
*/

#include "ProgressBar.hpp"

#include "ProgressBar.hpp"
#include <iostream>

/**
* Updates the progress bar.
* @param current The current progress.
* @param total The total progress.
**/
void Raytracer::ProgressBar::update(unsigned int current, unsigned int total)
{
    float progress = (float)current / total;
    int barWidth = 100;
    int pos = barWidth * progress;

    std::cerr << "\r[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos)
            std::cerr << "=";
        else
            std::cerr << " ";
    }
    std::cerr << "] " << int(progress * 100.0) << " %";

    if (current == total - 1) {
        std::cerr << "\r[" << std::string(barWidth, '=') << "] 100 %\n";
    }
}
