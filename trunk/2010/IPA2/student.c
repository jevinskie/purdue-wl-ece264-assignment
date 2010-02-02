/*
 * student.c
 *
 *  Created on: Jan 26, 2010
 *      Author: askiahill
 */

#include "student.h"

void AddStudent(NODEPTR database, FILE* fp)
{
	char IDnumber[21];
	char lastname[21];
	NODEPTR iter;
	fscanf(fp, "%s %s\n", IDnumber, lastname);

	if(database == NULL)
	{
		database = (NODE*)malloc(sizeof(NODE));
		if(database == NULL)
		{
			printf("Error allocating space! Exiting Program!");
			exit(-1);
		}

		strcpy(database->IDnumber, IDnumber);
		strcpy(database->lastname, lastname);
		database->next = NULL;
	}
	else
	{
		iter = database;
		while(iter->next == NULL)
		{
			iter = iter->next;
		}

		iter->next = (NODE*)malloc(sizeof(NODE));
		if(iter == NULL)
		{
			printf("Error allocating space! Exiting Program!");
			exit(-1);
		}

		strcpy(iter->IDnumber, IDnumber);
		strcpy(iter->lastname, lastname);
		iter->next = NULL;
	}
	return;
}

int Search(NODEPTR database, FILE* fp)
{
	char key[21];

	fscanf(fp, "%s\n", key);

	if(strtol(key,NULL,10))
	{
		SearchID(key, database);
	}
	else
	{
		SearchName(key, database);
	}
}

void SearchID(char* IDnumber, NODEPTR database)
{
	NODEPTR iter = database;
	if(iter == NULL)
	{
		printf("Database empty! ID not found\n");
	}
	else
	{
		while(iter != NULL)
		{
			if(!strcmp(iter->IDnumber, IDnumber))
			{
				PrintEntry(iter, 0);
				return;
			}

			iter = iter->next;
		}
	}
	return;
}

void SearchName(char* lastname, NODEPTR database)
{
	NODEPTR iter = database;
	if(iter == NULL)
	{
		printf("Database empty! Name not found\n");
	}
	else
	{
		while(iter != NULL)
		{
			if(!strcmp(iter->lastname, lastname))
			{
				PrintEntry(iter, 1);
			}

			iter = iter->next;
		}
	}
	return;
}

void Delete(NODEPTR database, FILE* fp)
{
	char key[21];

	fscanf(fp, "%s\n", key);

	if(strtol(key,NULL,10))
	{
		DeleteID(key, database);
	}
	else
	{
		DeleteName(key, database);
	}
}

void DeleteID(char* IDnumber, NODEPTR database)
{
	NODEPTR iter = database;
	NODEPTR prev, hold;
	if(iter == NULL)
	{
		printf("Database empty! Name not found\n");
	}
	else
	{
		if(!strcmp(iter->IDnumber, IDnumber))
		{
			hold = iter;
			iter = iter->next;
			free(hold);
			return;
		}

			iter = iter->next;
			prev = database;
			while(iter != NULL)
			{
				if(!strcmp(iter->IDnumber, IDnumber))
				{
					hold = iter;
					iter = iter->next;
					prev= iter;
					free(hold);
					return;
				}
				iter = iter->next;
				prev = prev->next;
			}
	}
	return;
}

void DeleteName(char* lastname, NODEPTR database)
{
	NODEPTR iter = database;
	NODEPTR prev, hold;
	int status = 0;

	while (status == 0)
	{
		if(iter == NULL)
		{
			printf("Database empty! Name not found\n");
			return;
		}

		status = 1;

		if(!strcmp(iter->lastname, lastname))
		{
			hold = iter;
			iter = iter->next;
			free(hold);
			status = 0;
		}
	}

	iter = iter->next;
	prev = database;
	while(iter != NULL)
	{
		if(!strcmp(iter->lastname, lastname))
		{
			hold = iter;
			iter = iter->next;
			prev= iter;
			free(hold);
		}
		iter = iter->next;
		prev = prev->next;
	}
	return;
}

void PrintEntry(NODEPTR iter, int choice)
{
	if (choice == 0)
		printf("Student name: %s\n", iter->lastname);
	else
		printf("Student ID: %s\n", iter->IDnumber);
	return;
}
