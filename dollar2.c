/****************************************************************************************************/
/* Name of file: dollar2.c                                                                          */
/* Purpose: The function determines the smallest number of $20, $10, $5, and $1 bills necessary to  */
/*          pay the amount represented by the dollars parameter. The main function displays the     */
/*          results.                                                                                */
/* Author: My Nguyen                                                                                */
/* Course: COP3514 MW 9:30-10:45am                                                                  */
/****************************************************************************************************/

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones); /* Declaration */
int dollar, twenty, ten, five, one; /* Global variable*/

int main(void)
{

	/* Read input with global variable dollar*/
	printf("Enter a dollar amount:");
  scanf("%d", &dollar);
  
  /* Use pay_amount function to pass the least number of bills */ 
  pay_amount(dollar, &twenty, &ten, &five, &one); 
  
  /* Prints values from pointers */
  printf("$20 bills: %d\n", twenty);
  printf("$10 bills: %d\n", ten); 
  printf("$5 bills: %d\n", five); 
  printf("$1 bills: %d\n", one); 
   
	return 0;
 
}

/* Function pay_amount is a hidden function that calculates the least number of bills necessary to pay the amount and returns the values to the respective pointer (twenties, tens, fives, and ones). The twenties pointer holds values of twenties, the tens pointer holds value of tens, etc. */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{

  /* Check the range of the input amount */
	if(dollar < 0 || dollar > 1000000000)
	   printf("Invalid amount %d,\nAmount must be between 0 and 1000000000, inclusive\n", dollar);
        else 
        {
  		      /* Calculates the amount bills needed from dollar amount */
            twenty = dollars/20;
        		ten = (dollars - (twenty * 20))/10;
            five = (dollars - (twenty * 20) - (ten * 10))/5;
            one = (dollars - (twenty * 20) - (ten * 10) - (five * 5)); 
            
            /* Pass values through pointers */
            *twenties = twenty;           
            *tens = ten;
            *fives = five;         
            *ones = one;
        }        
}
	


