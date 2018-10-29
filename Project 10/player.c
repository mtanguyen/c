#include <stdio.h> // input and output
#include <string.h> // string copy etc
#include <stdlib.h> // malloc
#include "player.h"
#include "readline.h"
	
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

  printf("\nPlayer Number\tLast Name\tFirst Name\n");
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