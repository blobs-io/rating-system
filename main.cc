#include <iostream>
#include <string>
#include <optparse/parser.hpp>
#include <cmath>

short calc(unsigned int own_br, unsigned int br_of_opponent)
{
        int gainValue = 0;
        int br_difference = own_br - br_of_opponent;
        if (br_difference < 0)
        {
                gainValue = pow(log10(-br_difference), 4);
        }
        else
        {
                gainValue = log1p(9998 / fdim(own_br, br_of_opponent));
        }
        if (own_br + gainValue >= 9999)
        {
                return 0;
        }
        if (gainValue > 999 || gainValue < 0) return 32;
        return gainValue == 0 ? ++gainValue : gainValue;
}

int main(int argc, char **argv)
{
    // Options
    // m = own BR
    // o = opponent BR
    optparse::parser parser(argc, argv, "mov");
	optparse::option* opts = parser.get_options();

	int own_br,
	opponent_br;

	for (int i = 0;; ++i) {
	    if (!opts[i].name) break;

        try {
	        if (opts[i].name == 'm') {
	            own_br = std::stoi(opts[i].value);
	        } else if (opts[i].name == 'o') {
	            opponent_br = std::stoi(opts[i].value);
	        } else if (opts[i].name == 'v') {
                std::cout << "blobs.io rating system v1.0.0\n";
                exit(0);
	        }
	    } catch(...) {
	        std::cerr << "Invalid BR value\n";
	    }
	}

	std::cout << calc(own_br, opponent_br);

	return 0;
}

