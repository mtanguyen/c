#ifndef PLAYER_H
#define PLAYER_H

// Defines name length
#define NAME_LEN 30

// Creates a structure player to get number, first and last name
struct player{
	int number;
	char first_name[NAME_LEN+1];
	char last_name[NAME_LEN+1];
	struct player *next;
};

// Declares function prototypes
struct player *append_to_list(struct player *roster);
void find_player(struct player *roster);
void printList(struct player *roster);
void clearList(struct player *roster);

#endif
