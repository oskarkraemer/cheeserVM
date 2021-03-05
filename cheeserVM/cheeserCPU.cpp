#include "cheeserCPU.h"

void cheeserCPU::step() {
	uint8_t opcode = memory[ip];
	uint16_t arguments = memory[ip+1] << 8 | memory[ip+2];

	//std::cout << "|Debug| Opcode: " << (int)opcode << std::endl;

	//Execute Instruction
	switch (opcode) {

	case OPCODE::SET:
		memory[mp+cp] = arguments;
		break;

	case OPCODE::SMP:
		mp = arguments;
		break;
	
	case OPCODE::INC:
		memory[mp+cp]++;
		break;

	case OPCODE::DEC:
		memory[mp+cp]--;
		break;

	case OPCODE::ADD:
		memory[mp + cp] = memory[mp + cp] + memory[arguments + cp];
		//std::cout << "Addition Info: Memory: " << (int)memory[mp + cp] << " Argument: " << (int)memory[arguments + cp] << "\n";
		break;

	case OPCODE::SUB:
		memory[mp + cp] = memory[mp + cp] - memory[arguments + cp];
		break;

	case OPCODE::JE:
		if (!memory[mp + cp]) {
			ip = (arguments-1)*3;
		}
		break;

	case OPCODE::JNE:
		if (memory[mp + cp]) {
			ip = (arguments-1)*3;
		}
		break;

	case OPCODE::EXIT:
		fg = FLAG::EXITF;
		break;

	case OPCODE::OUT:
		std::cout << char(memory[mp + cp]+48);
		break;

	default:
		fg = FLAG::INVALID_INSTRUCTION;
		break;
	}

	ip+=3;
}

void cheeserCPU::loadBinary(const std::string& filename)
{
	std::ifstream file(filename, std::ios::in | std::ios::binary);

	//Get file size
	const auto begin = file.tellg();
	file.seekg(0, std::ios::end);
	const auto end = file.tellg();
	const auto fsize = (end - begin);
	file.seekg(0, std::ios::beg);

	cp = fsize;
	std::cout << "|Debug| Loaded executable " << filename << " with file Size: " << fsize << " bytes" << std::endl;

	//Read contents
	file.read((char*)memory, fsize);
}
