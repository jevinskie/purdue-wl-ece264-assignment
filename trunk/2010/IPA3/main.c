
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "maze.h"
#include "linklist.h"
#include "stack.h"
#include "solver.h"

#define MAX_MAZE_WIDTH 80

/* Entry point */
int main(int argc, char * argv[])
{
  FILE * file;
  Maze * maze;

  if (argc < 2)
    {
      fprintf(stderr, "Missing filename.\n");
      return 2;
    }
  
  file = fopen(argv[argc - 1], "r");
  if (file == NULL)
    {
      fprintf(stderr, "Cannot open file.\n");
      return 1;
    }

  /* Read the file from file */
  maze = Maze_ReadFromFile(file, MAX_MAZE_WIDTH);

  /* Close the open file ASAP */
  fclose(file);

  /* Print out the maze first */
  Maze_Print(maze);

  /* Call the solver to solve the puzzle */
  SolveMaze(maze);
  
  /* Destruct the whole maze */
  Maze_Destruct(maze);

  /* End of program, successful */
  return 0;
}
