/*
 * main.c
 *
 *  Created on: Jan 26, 2010
 *      Author: askiahill
 */

#include "student.h"

int main(int argc, char* argv[])
{
	FILE* fp;
	NODEPTR database = NULL;
	NODEPTR iter1, iter2;
	char option;
	

	if (argc < 2)
	{
		printf("Not enough command line arguments, program exiting\n");
		exit(-1);
	}


	fp = fopen(argv[1], "r");

	while(fscanf(fp, "%c", &option) != EOF)
	{
		if(option == 'A')
		{
		  AddStudent(&database, fp);
		}
		else if(option == 'S')
		{
		  Search(database, fp);
		}
		else if(option == 'D')
		{
		  Delete(database, fp);
		}
	}

	fclose(fp);

	iter1 = database;
	while(iter1 != NULL)
	  {
	    iter2 = iter1;
	    iter1 = iter1->next;
	    free(iter2);
	  }
	return 0;
}
