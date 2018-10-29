/* 

   Name of file: voltage.c
   Purpose: Calculate the voltage across the capacitor
   Name of Author: My Nguyen
   Course: COP 3514 MW 9:30-10:45am
   
*/

#include <stdio.h>
#include <math.h> //Include math class for all math functions

//Declare all given constants 
#define VOLTAGE 10
#define RESISTANCE 3,000
#define CAPACITANCE 50E -6
#define TIMECONSTANT 0.15

int main(void)
{

	//Initialize variables 	
	float voltage_time;
	float time = 0;
	
	printf("time(sec) \t voltage \n");
	
	//Use for loop to determine the answer between 0 and 1 seconds
	for (time = 0; time <= 1; time = time + ((float) 1/15))
	{
		//Use the equation given
		voltage_time = VOLTAGE * (1 - exp(-time/TIMECONSTANT));
		printf("%.2f %15.2f \n", time, voltage_time);
	}
	
	return 0; 	
}
