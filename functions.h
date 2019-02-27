
//NAME : SUBHAM KUMAR DASH
//ID : 2017A7PS0004P


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* list[50]; // each index will store the index of head of a list
int* arr[999];

extern int num_list;
extern int* q;
//extern int* countTotal;

void createNewList();
void insertNewElement();
void deleteElement();
void countTotalElements();
void countTotalElementsOfList();
void displayLists();
void displayFreeList();
void performDefragmentation();
void exitOnCall();
void createInitialFreeList();
int countElements();
int elementsOfList(int list_num);
int numberOfList();
