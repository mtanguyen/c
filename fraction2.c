/*****************************************************************************************************/
/* Name of file: fraction2.c                                                                         */
/* Purpose: Reduced_numerator and reduced_denominator are pointers to variable in which the function */
/*          will store the numerator and denominator of the fraction once it has been reduced to     */
/*          lowest terms. Modify the main function so it calls reduce before displaying the result.  */ 
/* Author: My Nguyen                                                                                 */
/* Course: COP3514 MW 9:30-10:45am                                                                   */
/*****************************************************************************************************/

#include <stdio.h>
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
int find_gcd(int m, int n);
int numerator, denominator; // global varibale - used in both main and reduce functions

int main(void)
{
  int num1, denom1, num2, denom2, result_num, result_denom;
  char operator;

  printf("Enter two fractions separated by a +, -, * or / sign: ");
  scanf("%d/%d %c%d/%d", &num1, &denom1, &operator, &num2, &denom2);
      
  // holds the reduce function to provide the lowest term of both numerator and denominator
  switch (operator) {
    case '+':
      result_num = num1 * denom2 + num2 * denom1;
      result_denom = denom1 * denom2;
      numerator = result_num;       
      denominator = result_denom; 
      reduce(numerator, denominator, &result_num, &result_denom); 
      printf("The sum is %d/%d\n", result_num, result_denom);
      break;
    case '-':
      result_num = num1 * denom2 - num2 * denom1;
      result_denom = denom1 * denom2;
      numerator = result_num;       
      denominator = result_denom; 
      reduce(numerator, denominator, &result_num, &result_denom); 
      printf("The difference is %d/%d\n", result_num, result_denom);
      break;
    case '*':
      result_num = num1 * num2;
      result_denom = denom1 * denom2;
      numerator = result_num;       
      denominator = result_denom; 
      reduce(numerator, denominator, &result_num, &result_denom); 
      printf("The product is %d/%d\n", result_num, result_denom);
      break;
    case '/':
      result_num = num1 * denom2;
      result_denom = denom1 * num2;
      numerator = result_num;       
      denominator = result_denom; 
      reduce(numerator, denominator, &result_num, &result_denom); 
      printf("The quotient is %d/%d\n", result_num, result_denom);
      break;
    default:
      printf("Unrecognized operator: %c\n", operator);
  }

  return 0;
}

// find_gcd function reduces two fractions to lowest terms
int find_gcd(int m, int n)
{
    if (n == 0)
      return m;
    return find_gcd(n, m%n);
}
   
// reduce function has pointers to store the numerator and denominator of the reduced terms in reduced_numerator and reduced_denominator
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int common_factor; // local variable - used only in reduce function

    // calculates the reduced numerator and denominator
    common_factor = find_gcd(numerator, denominator);
    *reduced_numerator = numerator/common_factor; 
    *reduced_denominator = denominator/common_factor; 

}
