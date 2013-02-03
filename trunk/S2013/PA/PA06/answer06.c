#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa06.h"
#define MAXIMUM_LENGTH 80
int countStudent(char * filename, int * numberStudent)
/*
 * This function opens the file whose name is given as the first
 * argument. If the file cannot be opened, the function returns
 * EXIT_FAILURE.
 *
 * If the file is opened successfully, the function reads and counts
 * the number of students in the file. 
 *
 * Each student has an ID (integer) and a name (string).  For
 * simplicity, each student's name is only one string, not two for
 * first name an d last name.
 *
 * Each student's record uses one line; i.e., two students use two
 * differne
 *
 * The number of students is stored in numberStudent (notice that this
 * is a pointer).
 *
 * Please be careful not to count empty lines or the end of the file
 * as another student.  Otherwise, your program will print empty lines
 * in the output and this is incorrect.
 *
 * The function closes the file and returns EXIT_SUCCESS.
 */
{
  return EXIT_SUCCESS;
}
/*
 * ================================================
 */

Student * allocateStudent (int numberStudent)
/*
 * allocate enough memory space to store students' records for
 * numberStudent students.
 *
 * If memory allocation fails, return NULL.
 * If memory allocation succeeds, return the memory address;
 */
{
  return NULL;
}

/*
 * ================================================
 */

int readStudent(char * filename, Student * studentArray, 
		int numberStudent)
/*
 * This function opens the file whose name is given as the first
 * argument. If the file cannot be opened, the function returns
 * EXIT_FAILURE.
 *
 * If the file is opened successfully, the function reads the
 * students' records and store the data in the second argument.
 *
 * The function closes the file and returns EXIT_SUCCESS.
 */
{
  return EXIT_SUCCESS;
}

/*
 * ================================================
 */

int writeStudent(char * filename, Student * studentArray, 
		 int numberStudent)
/*
 * This function opens the file whose name is given as the first
 * argument. If the file cannot be opened, the function returns
 * EXIT_FAILURE.
 *
 * If the file is opened successfully, the function writes the
 * students' records to the file, one student per line.
 *
 * The function closes the file and returns EXIT_SUCCESS.
 */
{
  return EXIT_SUCCESS;
}


/*
 * ================================================
 */

/*
 * Write a comparison function based on students' IDs for qsort
 */

int compID(...)
{
  return 0;
}

/*
 * ================================================
 */

void sortStudentbyID(Student * studentArray, int numberStudent)
/*
 * This function sorts the students by their IDs.  
 *
 * You MUST use the qsort function in C library.  You must NOT
 * implement your own sorting function.  You will lose 20% points if
 * you implement your own sorting function.
 *
 */
 
{
  qsort(...);
}

/*
 * Write a comparison function based on students' names for qsort
 */

int compName(...)
{
  return 0;
}

/*
 * ================================================
 */

void sortStudentbyName(Student * studentArray, int numberStudent)
/*
 * This function sorts the students by their names.  
 *
 * You MUST use the qsort function in C library.  You must NOT
 * implement your own sorting function.  You will lose 20% points if
 * you implement your own sorting function.
 *
 */
 
{

}

/*
 * ================================================
 */

void freeStudent(Student * studentArray, int numberStudent)
{
}
