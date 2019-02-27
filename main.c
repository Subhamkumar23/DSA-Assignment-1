
//NAME : SUBHAM KUMAR DASH
//ID : 2017A7PS0004P


#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int num_list = 0;
int free_head = 0;
int *q = &free_head;

int main()
{
	createInitialFreeList();
	while(1){
		printf("Select an option:\n");
		printf("1. Create a new list\n");
		printf("2. Insert a new element in a given list in sorted order\n");
		printf("3. Delete an element from a given list\n");
		printf("4. Count total elements excluding free list\n");
		printf("5. Count total elements of a list\n");
		printf("6. Diaplay all lists\n");
		printf("7. Display free list\n");
		printf("8. Perform defragmentation\n");
		printf("9. Press 0 to exit\n");
		
		int option;
		scanf("%d",&option);
	
		switch(option)
		{
			case 1: createNewList();
				break;
			case 2: insertNewElement();
				break;
			case 3: deleteElement();
				break;
			case 4: countTotalElements();
				break;
			case 5: countTotalElementsOfList();
				break;
			case 6: displayLists();
				break;
			case 7: displayFreeList();
				break;
			case 8: performDefragmentation();
				break;
			case 0: exitOnCall();
				break;
			default: printf("Write a integer between 0 to 8\n");
		}
	}
	 

}


