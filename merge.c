/****************************************************************************************************/
/* Name of file: merge.c                                                                            */
/* Purpose: This program takes two sets of characters entered by the user and merge them character  */
/*            by character.                                                                         */
/* Author: My Nguyen                                                                                */
/* Course: COP3514 MW 9:30-10:45am                                                                  */
/****************************************************************************************************/

#include <stdio.h>
#include <string.h> //string library to use string functions
#define N 1000 // input is no longer than 1000 characters

void merge(char *s3, const char *s1, const char *s2);
int read_line(char *str, int n);


int main(void)
{

  char str1[N], str2[N], str3[N];
  
  
  printf("Enter the first set of characters: ");
  read_line(str1, N); //stores characters in str1
  
  printf("Enter the second set of characters: ");
  read_line(str2, N); //stores characters in str2
  
  merge(str3, str1, str2); //merges all elements from str1 and str2 into str3 
  
  printf("%s", str3); //prints str3 in merged order
    
  return 0;
  
}

//read_line reads each input character and terminates when it hits the null character '\0'
int read_line(char *str, int n)
{
  int ch, i = 0;
  
  while ((ch = getchar()) != '\n')
  {
    if (i < n)
    {
      *str++ = ch;
      i++;
    }
  }
  
  *str = '\0'; // terminates string
  return i; // number of characters stored
  
}

// merge function merges the characters in s1 and s2 and makes sure there it does not include the null character
void merge(char *s3, const char *s1, const char *s2)
{
  
   while (*s1 != '\0' && *s2 != '\0')
  {
    *s3 = *s1;
    s1 = s1 + 1; // increments to next index
    s3 = s3 + 1; // increments to next index to hold s2
    
    *s3 = *s2;
    s2 = s2 + 1;
    s3 = s3 + 1;
    
  }
  
  while (*s1 != '\0' && *s2 == '\0')
  {
    *s3 = *s1;
    s1 = s1 + 1;
    s3 = s3 + 1;
   
  }
  
  while (*s2 != '\0' && *s1 == '\0')
  {
 
    *s3 = *s2;
    s2 = s2 + 1;
    s3 = s3 + 1;
    
  }
  
}

