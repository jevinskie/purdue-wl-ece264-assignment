/*
 * Student.h should containd the library files you want to include in your 
 * program as well the headers to the functions that you are going to use.
 * 
 * 
 */
#ifndef STUDENT_H_
#define STUDENT_H_

#define MAXLENGTH 21

/* Definition of a node in the linked list */
typedef struct node
{
  char name[MAXLENGTH]; // holds the name of the student
  char IDnumber[MAXLENGTH]; //holds the ID number of the student
  struct node* next; // holds the address of the next ndoe in the linked list
}NODE;

void AddStudent();
void Search();
void SearchID();
void SearchName();
void Delete();
void DeleteID();
void DeleteName();
void PrintEntry();

#endif /* STUDENT_H_ */
