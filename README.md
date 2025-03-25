# LRU and Second Chance Algorithms

## Description  

This project implements the **Least Recently Used (LRU)** and **Second Chance (SC)** page replacement algorithms in C.  

## LRU Algorithm  

- Initially, the **Inverted Page Table** is allocated.  
- As long as there is available space, traces are stored as structs, while copies of addresses are stored in a **priority queue**.  
- If an address already exists in the page table, its priority is updated.  
- If the page table is full, the address with the **lowest priority** is removed (popped), and the new address is inserted in its place.  

## Second Chance (SC) Algorithm  

- This algorithm utilizes a **simple linked list**.  
- If an entry already exists, it updates the `second_c` flag to `1`.  
- If there is no space, the algorithm searches the entire list:  
  - If a node has `1` in `second_c`, it is reset to `0`.  
  - Otherwise, the node is removed (popped).  
- **Note:** The SC algorithm is not fully functional in this implementation.  

## Project Structure  

The project consists of the following directories and files: 

## Project Structure

- **bin/**  
  - `runner` - Executable file  

- **build/**  
  - Compiled `.o` object files  

- **headers/** (Header files)  
  - `InvertedPageTable.h`  
  - `list.h`  
  - `LRU.h`  
  - `queue.h`  
  - `SC.h`  
  - `Simulator.h`  

- **src/** (Source files)  
  - `InvertedPageTable.c`  
  - `list.c`  
  - `LRU.c`  
  - `main.c`  
  - `queue.c`  
  - `SC.c`  
  - `Simulator.c`  

- `Makefile` - Compilation instructions  
- `README.md` - Project documentation  


## How to Run the Program

The program is compiled using the `make` command and executed with either: `make run`

or, for execution with Valgrind: `make valgrind`



The default arguments are set in the Makefile (`lru`). The available arguments are:

- `-f <number>`: **Defines the number of frames.**  
- `-q <number>`: **Determines how often the program alternates reading from files.**  
- `-m <number>`: **Sets the maximum number of records to be read.**  
- `-a <algorithm>`: **Specifies the algorithm to be used.**  


## Code Structure

The **Simulator** file handles the necessary initializations and invokes the selected algorithm based on the provided arguments.

The **main** function reads the input arguments and calls the **Simulator**.




