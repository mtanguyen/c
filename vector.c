/****************************************************************************************************/
/* Name of file: vector.c                                                                           */
/* Purpose: Ask the user to enter the length of the vectors, declare two arrays with the legnth,    */
/*          read in the values for two vectors, and call the two functions to compute the           */
/*          multiplication and comparison of them. The main function displays the results.          */
/* Author: My Nguyen                                                                                */
/* Course: COP3514 MW 9:30-10:45am                                                                  */
/****************************************************************************************************/

#include <stdio.h>
#define N 10

//declarations
void multi_vec(int *v1, int *v2, int *v3, int n);
int comp_vec(int *v1, int *v2, int n);

int main(void)
{

  int n; 
  int *i, *j;
  int result; 
    
  printf("Enter the length of the vectors: \n");
  scanf("%d", &n);
  
  int a[n], b[n], c[n]; 
  
  //scans for the first vector's values using a for loop because a is an array
  printf("Enter the first vector: \n");
  for (i = a; i < a + n; i++)
    scanf("%d", i); 
   
  //scans for the second vector's values using a for loop because b is an array
  printf("Enter the second vector: \n");
  for (j = b; j < b + n; j++)
    scanf("%d", j); 
  
  //compare to see if the two vectors are equal to each other
  result = comp_vec(a, b, n);
  
  //multiples the two vectors and print the final vector
  printf("The multiplication of the vectors is: " );
  multi_vec(a, b, c, n);  
  
  printf("\n");
  
  if (result == 0)
    printf("The vectors are not the same. \n");
  else
    printf("The vectors are the same. \n");

  return 0;
  
}

/* multi_vec function multiples the first vector and second vector and stores the final result into the third vector. n is the length of the vectors */
void multi_vec(int *v1, int *v2, int *v3, int n)
{

  int *p, *q, *r;
  p = v1;
  q = v2;
  
/* scans the third array and put the values of the product of the first and second vector into the third array*/
  for (r = v3; r < v3 + n; r++)
  {   
      *r = (*v1 * *v2);
      v1 += 1;
      v2 += 1;
            
      printf(" %d", *r);
  }
}

/* comp_vec function compares the first and second vector. If the vectors are equal return 1 and return 0 otherwise. */
int comp_vec(int *v1, int *v2, int n)
{

   int temp = 1;
   int i;
   
   for (i = 0; i < n; i++)
   {
     if (*(v1 + i) != *(v2 + i))
     {
        temp = 0;
     }
   }

    return temp;
    
}

