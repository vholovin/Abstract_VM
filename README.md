# Abstract_VM - 42/Unit Factory

This project create program, which emulate work of Virtual Machine that uses a stack to compute simple arithmetic expressions. These arithmetic expressions are provided to the machine as basic assembly programs.

1. Use "make" to compile program.
2. run ./avm test/[choose_file] OR ./avm

First method read commands from file, second methods read commands from terminal.

BONUS: VM capable of diagnosing all errors in a file without stopping at the first error encountered.

# Instructions:

| Instruction  |  Details |
|---|---|
| **push _value_**  | Pushes the value v at the top of the stack. The _value_ must have one of the following form: <ul><li>int8(n) : Creates an 8-bit integer with value n.</li><li>int16(n) : Creates a 16-bit integer with value n.</li><li>int32(n) : Creates a 32-bit integer with value n.</li><li>float(z) : Creates a float with value z.</li><li>double(z) : Creates a double with value z.</li></ul>|
| **pop**  | Unstacks the value from the top of the stack. |
|  **dump**  |  Displays each value of the stack, from the most recent one to the oldest one. |
| **assert _value_** |  Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction. |
| **add**  |  Unstacks the first two values on the stack, adds them together and stacks the result. |
| **sub** |  Unstacks the first two values on the stack, subtracts them, then stacks the result. |
| **mul** |  Unstacks the first two values on the stack, multiplies them, then stacks the result. |
| **div** |  Unstacks the first two values on the stack, divides them, then stacks the result. |
| **mod** | Unstacks the first two values on the stack, calculates the modulus, then stacks the result. |
| **print** | Asserts that the value at the top of the stack is an 8-bit integer. (If not, see the instruction assert), then interprets it as an ASCII value and displays the corresponding character on the standard output. |
| **exit** | Terminate the execution of the current program. |
| **Comments** | Comments start with a ’;’ and finish with a newline. |
| **;;** | Close program. (Only for program, which works to read commands from terminal) |
