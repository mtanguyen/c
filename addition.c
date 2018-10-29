/*

  Name of file: addition.c
  Purpose: The + operator is not available. This program will take two numbers as input and display the addition of them. The function add will add two numbers using only     recursion. 
  Author: My Nguyen
  Course: COP 3514 9:30 - 10:45AM 

*/

#include <stdio.h>

// add function
int add(int n, int m); 

// display the answers using the add function
int main(void)
{
   int n = 0;
   int m = 0;
   int total; 
   
   printf("Enter two numbers: ");
   scanf("%d %d", &n, &m);
   
   total = add(n, m);
   
   printf("The addition is %d.", total);

   return 0;
}

/* function add will add two numbers using only recursion, increment and/or decrement operators */
int add(int n, int m)
{
  
  if (m < 0)
  {  
     return add(--n, ++m);
  }
  else if (m > 0)
  {    
      return add(++n, --m);
  }
  else 
    return n;
  
}


