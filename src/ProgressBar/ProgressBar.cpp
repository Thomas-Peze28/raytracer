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
    int barWidth = 50;
    int pos = barWidth * progress;

    std::cout << "\r[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos)
            std::cout << "=";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %";

    if (current == total - 1) {
        std::cout << "\r[" << std::string(barWidth, '=') << "] 100 %\n";
    }
    std::cout.flush();
}
