/*
 * ECE 264 Spring 2010
 * ipa1.c
 * 
 * by Yung-Hsiang Lu
 */
/*
 * count the occurrences of words in a file
 *
 * always need one argument as the input file name
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Assume each line has at most 80 letters.  The additional one letter
 * is used for the ending '\0'.
 */
#define MAX_LINE_LENGTH 81
/*
 * If a line has only one word, the maximum length of a word is the
 * length of a line.
 */
#define MAX_WORD_LENGTH MAX_LINE_LENGTH

/*
 * Two adjacent words are separated by one space.  Each line can have
 * at most so many words, assuming each word has only one letter (such
 * as an article "a").
 */
#define MAX_NUM_WORD_PER_LINE (MAX_LINE_LENGTH / 2 + 1)

/*
 * find the n-th word in a line, n starts at 0
 * return value
 *        1: the line has n words
 *        0: the line does not have n words
 * input arguments
 *        first: a line of words
 *        second: the space to store a word
 *        third: which word to find
 *  
 * WARNING: the space for the second argument must be allocated before
 * calling this function. This function does not allocate space.
 */
int findNthWord(char * line, char * word, int nth) {
  /*
   * find the beginning of the n-th word in a line
   * n starts from zero (for the first word)
   * If the line does not have n words, return NULL
   */
  /*
   * skip blank lines
   */
  if (strcmp(line, "") == 0)  
    /* 
       compare line with an empty line, not an empty string
     */
    {
      return 0;
    }
  int wordCnt = 0;
  /* create a pointer and make it point to the beginning of the line */
  strcpy(word, ""); /* clear the word */

  /* find the beginning of the n-th word */
  while (wordCnt < nth) {
    /* 
     * caution: wordPtr must use itself in strchr, not line. Using
     * line will keep wordPtr at the second word regardless of the
     * value of nth
     */
    /*
      use strchr to find the next space
    */
    /*
      if the next space does not exist, return 0
    */
    /*
      if the next word exists, move wordPtr forwad by one so that it
      points to the beginning of the next word
      
     */
    /*
      increment the counter by one
     */
  }
  
  /*
    copy the word from wordPtr to word
  */
  /* 
     make sure word contains only one word. 
     end the word with '\0' 
     wordPtr may contain several words
  */
  return 1;
}

/*
 * find whether a word has already occurred
 * return value
 * 	      the index of of the word in an array of words
 * input arguments
 *        first: an array of words
 *        second: a word to be found
 *        third: the number of words in the array
 */

int findIndex(char * * wordArray, char * word, int numWords) {
  return 0;
}

int main(int argc, char * argv[]) {
  if (argc < 2) {
    printf("need a file name\n");
    return -1;
  }
  FILE * fh;
  /*
    use fopen to open a file in the read mode
  */
  /*
    if fopen fails, print an error message
  */

  if (fh == NULL) {
    printf("fopen fail\n");
    return -1;
  }
  /* find the number of lines */
  /* assume each line has no more than 80 characters */
  /* printf("There are %d lines.\n", numLines); */
  /* 
     allocate memory 
     Each line has at most MAX_NUM_WORD_PER_LINE words
     Each word is no longer than MAX_WORD_LENGTH

     Need to use a two-dimensional array because each word is an array
     of char
  */

  /* return to the beginning of the file */
  fseek(fh, 0, SEEK_SET);
  /* read the file again. find the words */
    /* find each word in a line */
    /* if the word has been seen, increment the counter */
    /* if the word has not been seen, add it to the list of seen words */
  /* close the file */
  /* 
     print the word counts 
     using the following format
     printf("%s %d\n", word, count);
  */
  /* release memory */
  /* release the memory for the words first */
  /* release the arrays */
  return 0;
}

