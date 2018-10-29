/*****************************************************************************************************/
/* Name of file: frequency.c                                                                         */
/* Purpose: This program reads in a line of text and computes the frequency of the words in the text.*/ 
/*          The input contains words separated by white spaces, comma, period, or exclamation point. */
/*                                                                                                   */
/* Author: My Nguyen                                                                                 */
/* Course: COP3514 MW 9:30-10:45am                                                                   */
/*****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 1000
#define row 1000
#define col 50

void read_line(char *str, int n);

int main()
{

  // Initialize variables
  char input[N];
  char words[row][col + 1] = {};
  int frequency[N];
  int count = 0;
  int i = 0;
  int flag;

  // Prompt user to enter a line of text
  printf("Input: ");
  read_line(input, N + 1); 
  
  // Use String token to break up the line of code
  char *pch = strtok(input, " ,.!");
     
  // Break up the rest of the string into tokens and store the tokens into the array while counting the number of occurrences of each word
  while (pch != NULL) // while word is not equal to null, enter while loop
  {   
    for (i = 0; i < count; i++){
       if (strcmp(words[i], pch) == 0) // compare the word and the word in the 2D array
       {
          flag = 1;
          break;            
           
       } else {
       
         flag = 0;
         
       }   
       
     }
     if (flag == 1){
       frequency[i]++; // if two words are the same, increment the frequency
       
     } else if (flag == 0){
         
         strcpy(words[count], pch); // if the two words are different, copy from pch into 2D array
         frequency[count] = 1; // set frequency to 1 for the word seen without any other occurrences
         count++; 
     } 
     
    pch = strtok(NULL, " ,.!"); //continue to break line of text into words and while loop
    
   }
  
  printf("Output: \n"); 
  
  for(i = 0; i < count; i++)
  {          
     printf("%s\t%d\n", words[i], frequency[i]); // print words and their frequency
  } 
  
  return 0;
  
}

// Read_line function reads in character by character of the line of text
void read_line(char *str, int n)
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
}
 