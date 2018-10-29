/* 

   Name of file: dollar.c
   Purpose: Ask an user to enter a US dollar amount and show how to pay the amount in the smallest number of $20, $10, $5, and $1 
   Name of Author: My Nguyen
   Course: COP 3514 MW 9:30-10:45am
   
*/

#include <stdio.h>

#define JACKSON 20
#define HAMILTON 10
#define LINCOLN 5
#define WASHINGTON 1

int main(void)
{

	int amount = 0;
	int num_jackson = 0;
	int num_hamilton = 0;
	int num_lincoln = 0;
	int num_washington = 0;

	//Prompt user to enter dollar amount
	printf("Enter a dollar amount: ");
  	scanf("%d", &amount);
//	printf("%d \n", amount); 
  
	//Determine validity of amount
	if ((amount >= 0) && (amount <= 1000000000)) //inclusive
	{	
		
		//Does calulations and print amount 

   		num_jackson = amount/20;
		printf("$20 bill(s): %d \n", num_jackson);

		int remaining_amount = amount - num_jackson*JACKSON;

		num_hamilton = remaining_amount/10;
		printf("$10 bill(s): %d \n", num_hamilton);

		int remaining_amount_2 = remaining_amount - num_hamilton*HAMILTON;
 	
		num_lincoln = remaining_amount_2/5;
		printf("$5 bill(s): %d \n", num_lincoln);

   		int remaining_amount_3 = remaining_amount_2 - num_lincoln*LINCOLN;
		
 	 	num_washington = remaining_amount_3/1;
		printf("$1 bill(s): %d \n", num_washington);
 	} 

	else 
   		printf("The amount is not valid %d \n", amount);

	return 0; 	
}
