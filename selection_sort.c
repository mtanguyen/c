/****************************************************************************************************/
/* Name of file: selection_sort.c                                                                   */
/* Purpose: The function sorts the array of numbers and finds the largest value. Once largest value */
/*          is obtained, the function will put the largest value in the last at the end of the      */
/*          array.                                                                                  */
/* Author: My Nguyen                                                                                */
/* Course: COP3514 MW 9:30-10:45am                                                                  */
/****************************************************************************************************/

#include <stdio.h>
#define N 10

//Declarations
void selection_sort(int *a, int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);

int main(void)
{

  int *i;
  int a[N];
 
  printf("Enter %d numbers to be sorted: ", N);
  for (i = &a[0]; i < &a[N]; i++)
    scanf("%d", i);

  selection_sort(a, N); // call from the selection_sort function

  printf("In sorted order:");
  for (i = &a[0]; i < &a[N]; i++)
    printf(" %d", *i);
  printf("\n");

  return 0;
  
}

void selection_sort(int *a, int n)
{

  int *p = a;
 
  if (n == 0)
  {  
    return;
  } 

  else
  {  
    swap(p + n - 1, find_largest(a, n)); //stores the largest number in the last position and swap the largest value with the last index
    selection_sort(a, n - 1); //sort the values in order from smallest to largest
  }  
  
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

