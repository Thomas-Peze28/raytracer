/*
** EPITECH PROJECT, 2026
** raytracer
** File description:
** main
*/

#include "Core.hpp"

/** 
* @brief Display usage information for the raytracer
* @param argc The number of command line arguments
* @param argv The command line arguments
* @return 0 if help is displayed, 1 if usage is correct, 84 otherwise
**/
int usage(int argc, char *argv[])
{
    if (argc != 2 && argc != 4) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE> [-f <OUTPUT_FILE_NAME>]" << std::endl;
        return 84;
    }
    if (argc == 4 && std::string(argv[2]) != "-f") {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE> [-f <OUTPUT_FILE_NAME>]" << std::endl;
        return 84;
    }
    if (argc == 3 || (argc == 4 && (!argv[3] || std::string(argv[3]).empty()))) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE> [-f <OUTPUT_FILE_NAME>]" << std::endl;
        return 84;
    }
    if (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        std::cout << "Usage: ./raytracer <SCENE_FILE> [-f <OUTPUT_FILE_NAME>]" << std::endl;
        std::cout << "\t<SCENE_FILE>: Path to the scene configuration file." << std::endl;
        std::cout << "\t-f <OUTPUT_FILE_NAME>: Optional flag to specify the output file name for the rendered image." << std::endl;
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int return_val = usage(argc, argv);

    if (return_val != 1)
        return return_val;
    try {
        Raytracer::Scene scene;
        Raytracer::Parser parser;

        parser.loadScene(argv[1], scene);

        Raytracer::Core core;
        Raytracer::ProgressBar progressBar;

        std::string output_file_name;
        if (argc == 4)
            core.setOutputFileName(std::string(argv[3]) + ".ppm");
        else
            core.setOutputFileName("output.ppm");
        if (!core.openOutputFile()) {
            std::cerr << "Error: Could not open output file: " << core.getOutputFileName() << std::endl;
            return 84;
        }
        core._ambient_factor = scene._ambient_factor;
        core._diffuse_factor = scene._diffuse_factor;

        core.addObserver(&progressBar);

        return core.run(scene);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
