/*
  maze.c
  This module defines and implements Maze object and its behaviors
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "maze.h"
#include "linklist.h"

Maze * Maze_ReadFromFile(FILE * file, int maxwidth)
{
  /* TODO Handle file reading here */

  return maze;
}

/* Destruct the maze and release memory */
void Maze_Destruct(Maze * maze)
{
  /* TODO Place memory releasing code here */
}

/* Get one element in the maze */
char Maze_GetElement(Maze * maze, int x, int y)
{
  /* TODO Place code here to find an element in a maze by its
   * coordinate. */
}

/* Set one element in the maze */
char Maze_SetElement(Maze * maze, int x, int y, char element)
{
  /* TODO Place code here to set an element in a maze located by its
   * coordinate. */
}

/* Print the whole maze on the screen */
void Maze_Print(Maze * maze)
{
  /* TODO Place code here */
}
