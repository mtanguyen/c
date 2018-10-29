/*******************************************************************************************************/
/* Name of file: sort_commands.c                                                                       */
/* Purpose: Write a program sort_commands.c that sorts a series of words as command-line arguments.    */
/* Author: My Nguyen                                                                                   */
/* Course: COP3514 MW 9:30-10:45am                                                                     */
/*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *p, const void *q);

int main (int argc, char *argv[])
{
  int p;
  
  qsort(argv, argc, sizeof(char*), compare_strings);  
  for (p = 1; p < argc; p++){    
    printf("%s ", argv[p]); // prints out lines in order
  }
  printf("\n");
  
  return 0;
}

int compare_strings(const void *p, const void *q)
{

  return strcmp (*(char **)p, *(char **)q); // compare two strings 

}

