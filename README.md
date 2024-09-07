# Conway's Game of Life in C++

This is a simple implementation of Conway's Game of Life in C++ that simulates cellular automata. The program generates a random seed and evolves the grid based on the classic rules of the Game of Life.

## Features

- Random seed generator for initializing the grid.
- Customizable grid size, seed size, starting position, and simulation duration.
- Displays the evolving generations of cells.
- Console-based simulation using the `Sleep` function for time delay between generations.
- Handles toroidal (wrap-around) boundary conditions.

## How It Works

1. The user provides the size of the grid, the seed size, starting position, and the simulation duration.
2. The seed is randomly generated and placed on the grid.
3. The Game of Life rules are applied to evolve the grid for the specified duration:
   - Any live cell with fewer than two live neighbors dies (underpopulation).
   - Any live cell with two or three live neighbors survives.
   - Any live cell with more than three live neighbors dies (overpopulation).
   - Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

## Setup and Installation

### Requirements

- Windows OS (uses `windows.h` for `Sleep()` and `system("cls")` commands).
- A C++ compiler (e.g., `g++`, MSVC).

### Steps to Run

1. Clone the repository or download the source files.
   
   ```bash
   git clone https://github.com/your-username/conway-game-of-life-cpp.git
   cd conway-game-of-life-cpp

2. Compile the code using a C++ compiler:

    ```bash
    g++ -o game-of-life game-of-life.cpp

3. Run the executable:

    ```bash
    ./game-of-life
    
4. Follow the on-screen prompts to enter the grid size, seed size, starting position, and duration.
Example Usage

    ```bash
    Enter the size of 2D array (should be greater than 10): 20
    Enter the size of seed (should be between 5 and 10): 5
    Enter the starting position of the seed: 5
    Enter the duration for which the simulation should run (positive value): 50
The program will display the first generation, then evolve the grid based on the rules of Conway's Game of Life for the specified duration.

Sample Output
    
    First Generation:
                       
          0 0 0 0 0    
          0 0   0 0    
          0     0      
                       
                       
    Time Elapsed: 1
    Population: 6
    ...
Contributions
Feel free to contribute
