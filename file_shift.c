/*****************************************************************************************************/
/* Name of file: file_shiftc                                                                         */
/* Purpose: The program reads the content of the file and shifts the content by the shift amount,    */
/*           then writes the shifted message to a file with the same name but an added extension     */
/*            of .sft.                                                                               */
/* Author: My Nguyen                                                                                 */
/* Course: COP3514 MW 9:30-10:45am                                                                   */
/*****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#define LEN 1000

void shift(char *message, int shift_amount);
void read_line(char *str, int n);

int main()
{
   // Initialize variables
  char file_name[LEN];
  char *extension = ".sft";
  char msg[LEN];
  int shift_amount; 
   
  // Prompt user to input file's name
  printf("Enter the file name: ");
  read_line(file_name, LEN); // use read_line function to get the file's name
  
  // Prompt user to enter the shift amount 
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift_amount);
  
  // Read file 
  FILE *pFile = fopen(file_name, "r");
  
  if (pFile == NULL)
  {
    printf("Error opening file \n");
    return 1;
  }
  
  // Add .sft to the end of the file's name
  char *mod_name = strcat(file_name, extension);
  
  // Write file
  FILE *fp = fopen(mod_name, "w");
  
  //Reads from pFile with the message 
  while (fgets(msg, LEN, pFile) != NULL) 
  {
    shift(msg, shift_amount); // shift the message
    fprintf(fp, "%s", msg); // prints the message in the second file
  }
  
  printf("Output file name: %s \n", mod_name); // outputs new file's name
  
  fclose(pFile);   
  fclose(fp);

  return 0;  
   
}

// Read_line function reads and stores every character of the file's name
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

// Shift function shifts the letters based on the shift amount
void shift(char *message, int shift_amount)
{
  char *p;
  for (p = message; *p != '\n'; p++){
    if (*p >='a' && *p <= 'z')
    {
      *p = (((*p - 'a') + shift_amount)%26) + 'a';
      
    }
    else if (*p >= 'A' && *p <= 'Z')
    {
      *p = (((*p - 'A') + shift_amount)%26) + 'A';
    }
  }
  
}
