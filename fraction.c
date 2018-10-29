/* 
	Name of file: fraction.c
	Purpose: Asks user to enter two fractions separated by an operator and  calculate the result where program will add, subtract, multiply or divide.
	Name of Author: My Nguyen
	Course: COP3514 MW 9:30 - 10:45am
*/

#include <stdio.h>

int main(void)
{

	// Initialize variables	
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
 	int numerator;
	int denominator;
	char operand;
  		
	// Prompt user to enter the fractions and operator
	printf("Enter two fractions separated by the operator (+, -, *, /): ");
	scanf("%d/%d %c %d/%d", &a, &b, &operand, &c, &d);
 
	// Do the math calculations
	if ((b != d) && (operand != '*') && (operand != '/'))
	{
		a = a * d;
   		c = b * c;
   		b = b * d;
  		d = b;
     	}
 
	// Use switch statement to process the operator and the math
	switch(operand)
	{
		case '/':
            		numerator = (a*d);
              		denominator = (b*c);	 
			printf("The quotient is %d/%d \n", numerator, denominator);
			break;			
		case '*':
            		numerator = (a*c);
            		denominator = (b*d);
      			printf("The product is %d/%d \n", numerator, denominator);
			break;
		case '+':
            		numerator = (a+c);
                	denominator = b;
			printf("The sum  is %d/%d \n", numerator, denominator);
			break;
		case '-':
            		numerator = (a-c);
                	denominator = b;
      			printf("The difference is %d/%d \n", numerator, denominator);
			break;		
		default:
			printf("Unrecognized operator: %c \n", operand);
			break;
	}
	
		return 0;
}


