#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cmath>
#include "algrithms/blobrating.cc"

static std::string *commandLineArgs = new std::string {""};
static std::vector<std::string> *options = new std::vector<std::string> {};

bool vectorIncludes(std::vector<std::string> &vec, std::string key) {
	bool includes = false;
	for(std::string& v : vec) {
		if (v == key) includes = true;
	}
	return includes;
}

int main(int argc, char **argv)
{
	// argv to string
	for (int i = 0; i < argc; ++i) {
		*commandLineArgs += " ";
		*commandLineArgs += argv[i];
	}
	*commandLineArgs = commandLineArgs->substr(1);
	
	// Parse options
	std::smatch matched;
	std::regex optionExpr("--\\w+");
	std::regex_search(*commandLineArgs, matched, optionExpr);
	
	for (int i = 0; i < matched.size(); ++i) {
		options->push_back(matched[i]);
	}
	
	if(vectorIncludes(*options, "--br")) {
		unsigned int ownBR = atoi(argv[1]);
		unsigned int opponentBR = atoi(argv[2]);
		std::cout << calc(ownBR, opponentBR);
	}
	
	
	delete commandLineArgs;
	delete options;
	return 0;
}

