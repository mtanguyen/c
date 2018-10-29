/* 
	Name of file: holy_day.c
	Purpose: Provide the extension of a deadline to the following Monday if deadline landed on a holy-day or weekend.
	Name of Author: My Nguyen
	Course: COP3514 MW 9:30 - 10:45am
*/

#include <stdio.h>

int main(void)
{

	// Initialize variables	
	int today_day = 0;
	int days = 0;
	int due_date;
	int final_date;
	
	// Prompt user to enter today's day 
	printf("Please enter today's day (0 for Sunday, 1 for Monday, 2 for Tuesday, etc...): ");
	scanf("%d", &today_day);
 
 	// Provide error statement
	if ((today_day >= 0) && (today_day <= 6))
	{
		today_day = today_day;
	}
	else
	{
		printf("This day is not valid. The day should be between 0 and 6. \n");
		return 0; //Abort program
	}
 	// Prompt user to enter how many days is given to work on the task 
 	printf("Enter the number of days to do the work: ");
	scanf("%d", &days);
	
	// Provide calculations
	due_date = today_day + (days%7); 
	final_date = due_date%7;

	if (final_date == 5)
	{
		days = days + 3;
		final_date = 1;
	}
	else if (final_date == 6)
	{
		days = days + 2;
		final_date = 1;
	}
	else if (final_date == 0)
	{ 
		days = days + 1;
		final_date = 1;
	}

	// Switch the final date to the needed due day
	switch(final_date)
	{
		case 0:
			printf("The work is due on Sunday. \n");
      			printf("It is due in %d days. \n", days);
			break;			
		case 1:
			printf("The work is due on Monday. \n");
      			printf("It is due in %d days. \n", days);
			break;
		case 2:
			printf("The work is due on Tuesday. \n");
      			printf("It is due in %d days. \n", days);
			break;
		case 3:
			printf("The work is due on Wednesday. \n");
      			printf("It is due in %d days. \n", days);
			break;
		case 4:
			printf("The work is due on Thursday. \n");
      			printf("It is due in %d days. \n", days);
			break;
		case 5:
			printf("The work is due on Friday. \n");
      			printf("It is due in %d days. \n", days);
			break;
		case 6:
			printf("The work is due on Saturday. \n");
      			printf("It is due in %d days. \n", days);
			break;
		default:
			printf("The due date is not valid. The day should be between 0 and 6. \n");
			break;
	}
	
		return 0;
}

