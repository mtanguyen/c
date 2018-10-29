/****************************************************************************************************/
/* Name of file: command_sort.c                                                                     */
/* Purpose: This program sorts its command-line arguments of 10 numbers, which are assumed to be    */ 
/*            integers. The first command-line argument indicate whether the sorting is in          */
/*              descending order (-d) or ascending order (-a), if the user enters an invalid option,*/
/*              the program should display an error message.                                        */
/*                                                                                                  */
/* Author: My Nguyen                                                                                */
/* Course: COP3514 MW 9:30-10:45am                                                                  */
/****************************************************************************************************/

#include <stdio.h> 
#include <stdlib.h> //  atoi function
#include <string.h>

//Declarations
void selection_sort_a(int *a, int n);
void selection_sort_d(int *a, int n);
int *find_smallest(int *a, int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);

int main(int argc, char *argv[])
{
  
  int i,j;
  int array[argc];
 
  for (i = 0; i < argc; i++)
  {  
    *(array + i) = atoi(*(argv + i)); //stores the values in commmand lines to array
  }
    
  // if argv[1] is equal to -a, then it will sort the values in the command lines in ascending order
  if (strcmp(argv[1],"-a") == 0)  
  {

    selection_sort_a(array, argc); // call from the selection_sort_a function
    
    printf("Output:");
    for (j = 2; j < argc; j++)  // j = 2 is argv[2] which is where the number in the command line starts
    {   
      
      printf("%d ", array[j]); // prints the elements in order from smallest to greatest
        
     }   
  }  
  else if (strcmp(argv[1],"-d") == 0)// if argv[1] is equal to -d, then it will sort the values in the command lines in descending order
  {
     
    selection_sort_d(array, argc); // call from the selection_sort_d function
    
    printf("Output: ");
    for (j = 0; j < argc - 2; j++) // j = 0 is argv[0] which is where the number in the command line 
    {   
      
      printf("%d ", array[j]); // prints the elements in order from greatest to smallest
        
     }      
    
  }
  else
  {  printf("Invalid option for sorting."); }
    
      
  return 0;
  
}

// this function sorts the values in the command lines from smallest to largest = ascending order
void selection_sort_a(int *a, int n)
{

  int *p = a;
 
  if (n == 0)
  {  
    return;
  } 

  else
  {  
    swap(p + n - 1, find_largest(a, n)); //stores the largest number in the last position and swap the largest value with the last index
    selection_sort_a(a, n - 1); //sort the values in order from smallest to largest
  }  
  
}

// this function sorts the values in the command lines from largest to smallest = descending order
void selection_sort_d(int *a, int n)
{

  int *p = a;
 
  if (n == 0)
  {  
    return;
  } 

  else
  {  
    swap(p + n - 1, find_smallest(a, n)); //stores the smallest number in the last position and swap the smallest value with the last index
    selection_sort_d(a, n - 1); //sort the values in order from smallest to largest
  }  
   
}

//find_smallest function finds the smallest number in the array
int *find_smallest(int *a, int n)
{

  int *i;
  int *min = a;
  
  for (i = a + 1; i < a + n; i++)
  {  
    if (*i < *min)
     { 
       min = i;
     }
  }
  
  return min; 

}

//find_largest function finds the largest number in the array
int *find_largest(int *a, int n)
{

  int *i;
  int *max = a;
  
  for (i = a + 1; i < a + n; i++)
  {  
    if (*i > *max)
     { 
       max = i;
     }
  }
  
  return max; 

}

//swap function swaps the values of two addresses
void swap(int *p, int *q)
{

  int temp;
  
  temp = *p;
  *p = *q;
  *q = temp;
  
}

