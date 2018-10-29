/*******************************************************************************************************/
/* Name of file: roster.c                                                                              */
/* Purpose: The program roster.c maintains a roster for a sports team. Each player has a last name,    */
/*           first name, and a number. It appends a player's information, find a player, prints the    */ 
/*           roster, and clear the list.                                                               */
/* Author: My Nguyen                                                                                   */
/* Course: COP3514 MW 9:30-10:45am                                                                     */
/*******************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Defines name length
#define NAME_LEN 30

// Creates a structure player to get number, first and last name
struct player{
	int number;
	char first_name[NAME_LEN+1];
	char last_name[NAME_LEN+1];
	struct player *next;
};

// Declares functions
struct player *append_to_list(struct player *roster);
void find_player(struct player *roster);
void printList(struct player *roster);
void clearList(struct player *roster);
int read_line(char str[], int n);

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

/**********************************************************
 * append_to_list: Prompts the user to enter a player's   *
 *                 number and that player's information   *
 *                 (last and first name). If a number     * 
 *                 already exists, user has to create     * 
 *                 another player.                        *
 **********************************************************/
struct player *append_to_list(struct player *roster){
   
  struct player *p;
  struct player *new_node; // Stores all information
  char first[NAME_LEN+1];
  char last[NAME_LEN+1];
  int found; // Boolean variable
  int number_of_player;
  p = roster;
  
  // Asks for player's information
  printf("Enter player number: ");
  scanf("%i", &number_of_player);
  found = 0;
   
  // Determines if the number is found
  while (p != NULL)
  { 
    if (p->number == number_of_player)
      found = 1;
    p = p->next;
  }
     
  // If player is found, it returns the roster and exits 
  if (found == 1)
  {
    printf("Player already exists.\n");
    return roster;
  }
  
  // If player does not exist, it allocated memory for player, store the data, and append the player to the end of the linked list 
  else{     
      
    printf("Enter player last name: ");
    read_line(last, NAME_LEN+1);
    
    printf("Enter player first name: ");
    read_line(first, NAME_LEN+1); 
     
    new_node = (struct player *)malloc(sizeof(struct player));   
    strcpy(new_node->first_name, first);
    strcpy(new_node->last_name, last);
    new_node->number = number_of_player;
    new_node->next = NULL;
    
    if(roster == NULL)
    {
      return new_node; // Returns pointer to newly created player
    }
    else{              // Player is added to end of list and return pointer to linked list
      p = roster;
      while (p->next != NULL){
        p = p->next;       
      }
      
      p->next = new_node; 
      return roster; 
    }  
  }
  
}

/**********************************************************
 * find_player: Prompts the user to enter a player's      *
 *              number and if the number is found, it     *
 *              prints the player's last then first name  *
 **********************************************************/
void find_player(struct player *roster)
{
	 int num_of_player;
   
  // Asks user to enter the player's number
  printf("Enter player number: ");
  scanf("%d", &num_of_player);

  // Runs while roster is not at the end of the list
  while (roster != NULL){
  
    // If player is found, then print his/her last then first name
    if (roster->number == num_of_player){
    
      printf("%s %s\n", roster->last_name, roster->first_name);
      break;
      
    }
    roster = roster-> next;
  }
  
  // If player is not found, then player does not exist
  if (roster == NULL){
      printf("Player not found.\n");
  } 

}

/**********************************************************
 * printList: Prints the credentials of all the players   *
 *            in the roster.                              *
 **********************************************************/
void printList(struct player *roster){

  printf("\nPlayer Number\tLast Name\tFirst name\n");
	while (roster != NULL){
  
    printf("%d\t\t%s\t\t%s\n", roster->number, roster->last_name, roster->first_name);
    roster = roster->next;
  }
 
}

/**********************************************************
 * clearList: Clears the memory when the user exits       *
 *              the program.                              *
 **********************************************************/
void clearList(struct player *roster)
{
  struct player *p;
  
  while (roster != NULL){
    p = roster;
    roster = roster->next;
    free(p);    
  }

}

/**********************************************************
 * read_line: read character by character  *
 **********************************************************/
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
 }

 
 

