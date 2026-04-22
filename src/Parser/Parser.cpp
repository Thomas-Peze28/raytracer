/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** Parser
*/

#include "Parser.hpp"

Raytracer::Parser::Parser()
{
}

Raytracer::Parser::~Parser()
{
}

void Raytracer::Parser::parseSceneFile(const std::string &scene_file)
{
    if (!std::filesystem::exists(scene_file))
        throw ErrorCritical("Scene file error: The file '" + scene_file + "' does not exist.");
    if (!std::filesystem::is_regular_file(scene_file))
        throw ErrorCritical("Scene file error: '" + scene_file + "' is not a valid regular file.");
}