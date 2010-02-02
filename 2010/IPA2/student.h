/*
 * student.h
 *
 *  Created on: Jan 26, 2010
 *      Author: askiahill
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define struct node
{
	char name[21];
	char IDnumber[21];
	node* next;
}NODE;

#define node* NODEPTR;

int AddStudent(NODEPTR database, FILE* fp);
void Search(NODEPTR database, FILE* fp);
void SearchID(char* IDnumber, NODEPTR database);
void SearchName(char* lastname, NODEPTR database);
void Delete(NODEPTR database, FILE* fp);
void DeleteID(char* IDnumber, NODEPTR database);
void DeleteName(char* lastname, NODEPTR database);
void PrintEntry(NODEPTR iter);

#endif /* STUDENT_H_ */
