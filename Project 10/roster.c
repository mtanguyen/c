/*******************************************************************************************************/
/* Name of file: roster.c                                                                              */
/* Purpose: The program roster.c maintains a roster for a sports team. Each player has a last name,    */
/*           first name, and a number. It appends a player's information, find a player, prints the    */ 
/*           roster, and clear the list.                                                               */
/* Author: My Nguyen                                                                                   */
/* Course: COP3514 MW 9:30-10:45am                                                                     */
/*******************************************************************************************************/

#include <stdio.h>
#include "player.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  
  char code;

  struct player *team_roster = NULL;  
  
  printf("Operation Code: a for appending to the roster, f for finding a player, p for printing the roster, q for quit.\n");
 
  for (;;) {
    
    // Prompts user to enter operation code
    printf("Enter operation code: ");
    scanf(" %c", &code);
    
    while (getchar() != '\n')   /* Skips to end of line */
      ;
    
    // Checks which operation was used to call the correct function
    switch (code) {
      case 'a': team_roster = append_to_list(team_roster);
                break;
      case 'f': find_player(team_roster);
                break;
      case 'p': printList(team_roster);
                break;
      case 'q': clearList(team_roster);
		            return 0;
      default:  printf("Illegal code\n");
    }    
    printf("\n");
  }
  
}