#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

#define SWAP(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))

typedef struct tagRectangle
{
  int x;
  int y;
  int width;
  int height;
} RECT;

// Read one rectangle from file and put it into linked list
int readRectDimension(FILE * finput, LinkList list)
{
  RECT * pRect = malloc(sizeof(RECT));
  if (pRect == NULL)
    {
      // Memory allocation error
      return 0;
    }
  if (fscanf(finput, "%d %d", 
	     &(pRect -> width), &(pRect -> height)) != 2)
    {
      // End of file or corrupt value
      free (pRect);
      return 0;
    }
  LinkList_Append(list, pRect);
  return 1;
}

// Fill the position info for rectangles in the linked list
int readRectPositions(FILE * finput, LinkList list)
{
  int swapFlag = 0;
  ListNode * pNode = LinkList_GetNode(list, 0);
  RECT * pRect;
  while (pNode != NULL)
    {
      // Get the current rectangle
      pRect = (RECT *)(pNode -> p_data);
      if (pRect == NULL)
	{
	  // Corrupted node?
	  return 0;
	}

      if (fscanf(finput, "%d %d %d", 
		 &(pRect -> x), &(pRect -> y), &swapFlag) != 3)
	{
	  // Unexpected input
	  return 0;
	}

      // Fancy swapping (you should understand but avoid using)
      if (swapFlag)
	{
	  int temp = pRect -> width;
	  pRect -> width = pRect -> height;
	  pRect -> height = temp;
	}

      // Go to next rectangle
      pNode = pNode -> p_next;
    }

  if (fscanf(finput, "%d", &swapFlag) == 1)
    {
      // Excessive input information
      return 0;
    }

  return 1;
}

int isValid(RECT * pRect)
{
  if (pRect -> width <= 0 || pRect -> height <= 0 ||
      pRect -> x < 0 || pRect -> y < 0)
    {
      return 0;
    }
  
  return 1;
}

int isOverlapping(RECT * pRect1, RECT * pRect2)
{
  if (pRect1 -> x >= pRect2 -> x + pRect2 -> width  ||
      pRect2 -> x >= pRect1 -> x + pRect1 -> width  ||
      pRect1 -> y >= pRect2 -> y + pRect2 -> height ||
      pRect2 -> y >= pRect1 -> y + pRect1 -> height)
    {
      return 0;
    }
  
  return 1;
}

int validateRectangles(LinkList list)
{
  ListNode * pNode = LinkList_GetNode(list, 0);
  ListNode * pNext;
  RECT * pRect1;
  RECT * pRect2;
  
  while (pNode != NULL)
    {
      pRect1 = (RECT *)(pNode -> p_data);
      if (!isValid(pRect1))
	{
	  return 0;
	}
      pNext = pNode -> p_next;
      while (pNext != NULL)
	{
	  pRect2 = (RECT *)(pNext -> p_data);
	  if (isOverlapping(pRect1, pRect2))
	    {
	      printf("overlap detected:\n");
	      printf("(%d, %d) - [%d x %d]\n", 
		     pRect1 -> x, pRect1 -> y,
		     pRect1 -> width, pRect1 -> height);
	      printf("(%d, %d) - [%d x %d]\n", 
		     pRect2 -> x, pRect2 -> y,
		     pRect2 -> width, pRect2 -> height);
	      return 0;
	    }
	  pNext = pNext -> p_next;
	}
      pNode = pNode -> p_next;
    }

  return 1;
}

long getTotalArea(LinkList list)
{
  ListNode * pNode = LinkList_GetNode(list, 0);
  RECT * pRect;
  long sum = 0;
  while(pNode != NULL)
    {
      pRect = (RECT *)(pNode -> p_data);
      sum += (pRect -> width * pRect -> height);
      pNode = pNode -> p_next;
    }

  return sum;
}

long getBoundArea(LinkList list)
{
  ListNode * pNode = LinkList_GetNode(list, 0);
  RECT * pRect;
  long maxX = 0, maxY = 0;
  int x, y;
  while(pNode != NULL)
    {
      pRect = (RECT *)(pNode -> p_data);
      x = pRect -> x + pRect -> width;
      y = pRect -> y + pRect -> height;
      if (x > maxX)
	{
	  maxX = x;
	}
      if (y > maxY)
	{
	  maxY = y;
	}
      pNode = pNode -> p_next;
    }

  return (maxX * maxY);
}

int main(int argc, char * argv[])
{
  if (argc < 3)
    {
      fprintf(stderr, "Missing file name.\n");
      return 1;
    }
  FILE * finput = fopen(argv[1], "r");
  if (finput == NULL)
    {
      fprintf(stderr, "Cannot open file.\n");
      return 2;
    }
  FILE * fcheck = fopen(argv[2], "r");
  if (fcheck == NULL)
    {
      fprintf(stderr, "Cannot open file.\n");
      return 2;
    }

  LinkList list = LinkList_Construct();

  // Reads rectangle dimensions from file into linked list
  while(readRectDimension(finput, list));
  fclose(finput);

  // Reads rectangle positions from standard input
  if (!readRectPositions(fcheck, list))
    {
      // Something is wrong
      printf("Incorrect output.\n");
      return 1;
    }
  fclose(fcheck);

  // Validates the whole list
  if (!validateRectangles(list))
    {
      return 1;
    }

  // Calculates total area
  long totalArea = getTotalArea(list);
  long boundArea = getBoundArea(list);
  printf("Area sum: %ld\n", totalArea);
  printf("Area required: %ld\n", boundArea);

  // Release Linked List
  LinkList_Destruct(list, NULL);
  return 0;
}
