#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include <fstream>


enum OPCODE{
	SET, SMP, INC, DEC, ADD, SUB, JE, JNE, EXIT, OUT, INP
};

enum FLAG {
	NONE, EXITF, INVALID_INSTRUCTION
};

class cheeserCPU
{
public:
	uint16_t ip = 0; //Instruction Pointer
	uint16_t mp = 0; //Memory Pointer
	uint16_t cp = 0; //Code pointer

	uint8_t fg = FLAG::NONE;

	uint8_t* memory; //65,535kb Memory

	cheeserCPU() {
		memory = new uint8_t[65535]();
	}

	~cheeserCPU() {
		delete[] memory;
	}

	void step();
	void loadBinary(const std::string& filename);
};

