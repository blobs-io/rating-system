#include <iostream>

#include <string>

#include <fstream>

#include <optparse/parser.hpp>

#include <cmath>

int main(int argc, char ** argv) {
    // Options
    // m = own BR
    // o = opponent BR
    // v = version
    // h = display readme
    optparse::parser parser(argc, argv, "movh");
    std::vector < optparse::option > opts = parser.get_options();

    int own_br,
    opponent_br;

    for (int i = 0; i < opts.size(); ++i) {
        try {
            if (opts[i].name == "m") {
                own_br = std::stoi(opts[i].value);
            } else if (opts[i].name == "o") {
                opponent_br = std::stoi(opts[i].value);
            } else if (opts[i].name == "v") {
                std::cout << "blobs.io rating system v1.0.1\n";
                exit(0);
            } else if (opts[i].name == "h") {
                std::ifstream fd("./README");
                std::string temp;
                std::cout << "blobs.io help page\n";
                while (getline(fd, temp)) {
                    std::cout << temp << "\n";
                }
                exit(0);
            }
        } catch (std::invalid_argument) {
            std::cerr << "Parameter is not a valid number\n";
        }
    }

    std::cout << calc(own_br, opponent_br);

    return 0;
}
