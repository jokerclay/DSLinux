# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

DSLinux is a C++ educational data structures and algorithms learning project. The project implements fundamental data structures with both C and C++ files, focusing on clarity and learning rather than production optimization.

## Build Commands

### Main Program
```bash
./run.main.sh    # Build and run main.cpp (demonstrates binary tree operations)
```

### Test Suite
```bash
./run.testcases.sh    # Build and run all test cases in TestCases/ directory
```

### Individual Component Testing
The build system compiles components individually. Each test case requires linking with its corresponding data structure implementation:

```bash
# Example: Build individual stack test
g++ -c -ggdb ./DSLog/DSLog.cpp -o ./objs/DSLog.o
g++ -c -ggdb ./Stack/Stack.cpp -o ./objs/Stack.o
g++ -c -ggdb ./TestCases/stack/sqStack.cpp -o ./objs/sqStack.o
g++ -ggdb -static ./objs/DSLog.o ./objs/Stack.o ./objs/sqStack.o -o ./objs/sqStack
./objs/sqStack
```

All object files are created in `./objs/` directory.

## Architecture

### Core Data Structure Components
- **Array/**: Matrix operations and specialized array representations (symmetric, sparse)
- **List/**: Sequential list, linked list, double linked, circular, and static linked list implementations
- **Stack/**: Both array-based (`sqStack`) and linked (`linkedStack`) implementations
- **Queue/**: Sequential queue implementation with circular queue support
- **Tree/**: Binary search tree with recursive traversal algorithms
- **String/**: String manipulation and operations
- **DSLog/**: Shared logging utility used across components

### Algorithm Collections
- **Sort/**: 7 sorting algorithms (insert, shell, bubble, quick, select, heap, merge) with numbered subdirectories
- **Search/**: Search algorithms including Red-Black Tree implementation in RBT/

### Testing Structure
`TestCases/` contains demonstration programs for each data structure:
- Each test case is a standalone program showing usage patterns
- Tests are organized by data structure type (list/, stack/, queue/, etc.)
- Some tests require external data files (e.g., bracketmatching)

### Dependencies
- Most components depend on `DSLog/DSLog.cpp` for logging
- BinaryTree implementation requires Queue for level-order traversal
- Build system uses static linking (`-static`) for all components

## Development Notes

### Type System
The project uses C-style #define macros for generic types rather than C++ templates:
- `sqStackElementType`, `sqQueueElementType` for basic structures
- `BITREEDATATYPE` for binary tree nodes
- Fixed size constants like `sqStackMaxSize 50`, `sqQueueMaxSize 255`

### Memory Management
- Uses C-style malloc/free in some components (BinaryTree)
- Uses C++ new/delete in others
- Manual memory management throughout - be careful with leaks

### Mixed Language Implementation
- Both .cpp and .c files present
- Some components use C-style structs with C++ compilation
- BinaryTree uses C memory allocation but C++ syntax

### Known Issues in Current Implementation
- Variable-length array allocation in Array.cpp (unsafe for large inputs)
- Missing malloc failure checks in several components
- Inconsistent naming conventions (e.g., "squence" vs "sequence")
- Some declared list types in headers lack implementations