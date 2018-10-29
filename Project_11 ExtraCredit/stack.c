#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**********************************************************
 * push: push and add a new value                         *
 **********************************************************/
struct node* push(struct node* top, int i)
{
   struct node *new_node;
   new_node = malloc(sizeof(struct node));
   if(new_node == NULL)
   {
	printf("malloc failed");
        return top;
   }
   
   new_node->value = i;
   new_node->next = top;
   return new_node;
}

/**********************************************************
 * make_empty: release all the memory allocated for the   *
 *             stack and update the stack by return NULL  *
 **********************************************************/
struct node *make_empty(struct node *top)
{

  struct node *s;
  
  // free memory
  while(top != NULL)
  {
	 s = top; 
	 top = top->next;
         if(s != NULL)
	    free(s);
  }
  
  return NULL; 
}

/**********************************************************
* pop: remove the top item from the stack, the function   *
*       should save the value of the popped item pointed  *
*       by the second pointer variable and update the     *
*       stack by returning the address of the top item    *
*       on the stack.                                     *
 **********************************************************/
struct node *pop(struct node *top, int *i)
{

  struct node *p;
  
  if (top != NULL){
  
    *i = top->value;
    p = top->next;
    free(top);
    return p;
  }
  
  return top;
}

/**********************************************************
 * roll: rolls the top three items on the stack and       *
 *        it returns the head of the linked list          *
 **********************************************************/
struct node *roll(struct node *top)
{   
  int one, two, three;
 
  // pop and rush top values 
  top = pop(top, &one);
  top = pop(top, &two);
  top = pop(top, &three);
  
  top = push(top, two);
  top = push(top, one);
  top = push(top, three);
  
  return top;
}

/**********************************************************
  * print_stack: prints the numbers                       *
***********************************************************/
void print_stack(struct node *top)
{
   struct node *p;
   if(top != NULL){
      for(p = top; p !=NULL; p=p->next)
	printf("%d\n", p->value);
      printf("\n");
   }
   else
      printf("stack is empty\n");
}