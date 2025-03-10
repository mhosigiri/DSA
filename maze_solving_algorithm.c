#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For usleep() to slow down display

// Dimensions of the maze
#define ROWS 12
#define COLS 12

// Function to print the maze
void printMaze(char maze[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    usleep(500000); // Delay to visualize steps (0.5 seconds)
}

// Function to check if the current position is an exit
bool isExit(int x, int y, char maze[ROWS][COLS])
{
    // An exit is on the border, not a wall, and not the starting position
    return (x == 0 || x == ROWS - 1 || y == 0 || y == COLS - 1) &&
           maze[x][y] != '#' && !(x == 2 && y == 0); // Assuming start at (2,0)
}

// Recursive function to traverse the maze using the right-hand rule
bool mazeTraverse(char maze[ROWS][COLS], int x, int y)
{
    // Base cases: out of bounds, wall, or already visited
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == '#' || maze[x][y] == 'X')
    {
        return false;
    }

    // Mark current position as part of the path
    maze[x][y] = 'X';
    printMaze(maze); // Display maze after each step

    // Check if this position is an exit
    if (isExit(x, y, maze))
    {
        printf("Exit found at (%d, %d)!\n", x, y);
        return true;
    }

    // Directions for right-hand rule: right, down, left, up (relative to current direction)
    int dx[] = {0, 1, 0, -1}; // Changes in x (row)
    int dy[] = {1, 0, -1, 0}; // Changes in y (col)

    // Try each direction (right-hand rule: prioritize right relative to current facing)
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (mazeTraverse(maze, newX, newY))
        {
            return true;
        }
    }

    return false; // No exit found from this path
}

int main()
{
    // Initialize the maze as given
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    printf("Initial Maze:\n");
    printMaze(maze);

    // Start at position (2,0) as an example (first '.' on the left border)
    int startX = 2, startY = 0;
    printf("Starting traversal from (%d, %d)...\n", startX, startY);

    if (!mazeTraverse(maze, startX, startY))
    {
        printf("No exit found.\n");
    }

    return 0;
}