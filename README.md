# cheeserVM
A virtual machine with a custom instruction set.
<pre>
Usage:
cheeserVM.exe -i cheeserExecutable.bin | Executes a given cheeserBinary

Architecture:
IP = 0 = Instruction pointer points to the next instruction in a program.
MP = 0 = Memory pointer holds a adress of memory
CP = 0 = Code pointer points at the end of the program

Memory = 65535 bytes = 65,535kb Max Memory
Memory adress width = 2 bytes

Instruction = 3 bytes width = [1. byte = opcode, 2. and 3. byte = additional parameters, e.g. memory adress]


Instruction Set:
XX = 2 byte parameter

0x00: SET XX - Sets the value XX at MP
0x01: SMP XX - Sets the MP to a memory-adress

-- Arithmetic operators --

0x02: INC - Increments the value at MP by 1
0x03: DEC - Decrements the value at MP by 1
0x04: ADD XX - Adds the value at XX in memory to the value of MP in memory and stores the result at MP
0x05: SUB XX - Subtracts the value at XX in memory to the value of MP in memory and stores the result at MP

-- Control Flow --

0x06: JE XX - Jumps to the XXth Instruction if the value at MP is 0
0x07: JNE XX - Jumps to the XXth Instruction if the value at MP is not 0
0x08: EXIT - Stops the program.

-- Console --

0x09: OUT - Prints the value at MP to the console.
0x0A: INP - Gets one byte from console.
</pre>
