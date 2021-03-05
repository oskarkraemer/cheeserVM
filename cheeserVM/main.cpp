#include <iostream>
#include "cxxopts.hpp"

#include "cheeserCPU.h"

int main(int argc, char** argv) {
	//Configure Console Argument Parser
	cxxopts::Options options("CheeserVM", "A 16bit based virtual machine with custom instruction set.");

	options.add_options()
		("i,input", "Run a .bin chesser executable", cxxopts::value<std::string>())
		("h,help", "Print usage")

	;

	auto result = options.parse(argc, argv);

	//Check parsed Console Arguments
	if (result.count("input")) {
		std::cout << result["input"].as<std::string>() << std::endl;
	}

	if (result.count("help")) {
		std::cout << options.help() << std::endl;
	}

	//Init cheeserVM
	cheeserCPU cpu;

	cpu.loadBinary("test.bin");
	
	while (cpu.fg != FLAG::EXITF) {
		cpu.step();
	}

	return 0;
}