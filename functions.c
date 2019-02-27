
//NAME : SUBHAM KUMAR DASH
//ID : 2017A7PS0004P


#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void createInitialFreeList()   //This function initializes the array with free list
{
	for(int i=0; i<332; i++)
	{
		arr[3*i+1] = malloc(sizeof(int));
		*arr[3*i+1] = 3*(i+1);
	}
}


void createNewList()
{
	int i=0;
	while(arr[3*i] != NULL)
	{
		i = i+1;
	}
	

	int *p = &num_list;
	(*p)++;
	printf("The sequence number of newly created list is: %d\n",*p);
	
	list[(*p)-1] = malloc(sizeof(int));
	*list[(*p)-1] = 3*i;

	printf("Enter key value to be inserted in the newly created list-%d: \n",*p);
	int key;
	scanf("%d",&key);
	
	arr[3*i] =  malloc(sizeof(int));
	*arr[3*i] = key;
	arr[3*i+1] = NULL;
	arr[3*i+2] = NULL;

	*q = 3*(i+1); // setting position for head of free list
	
	printf("SUCCESSFULLY CREATED LIST\n");
}

void insertNewElement()
{
	printf("List you want to insert in: \n");
	int list_num;
	scanf("%d",&list_num);

	if(list[list_num-1] == NULL )
	{
		printf("Sorry! List number %d does not exist.\n",list_num );
		exit(0);
	}

	printf("Enter the key value: \n");
	int key;
	scanf("%d",&key);
	

	int count = 0;
	int k = *list[list_num-1]+1;
	while(arr[k] != NULL)
	{
		count++;
		k = *arr[k]+1;
	}
	if(arr[k+1]!=NULL)
		count++;
	else if(arr[k+1] == NULL && arr[k-1] != NULL)
		count++;

	if(count == 0)
	{
		arr[*list[list_num-1]] = malloc(sizeof(int));
		*arr[*list[list_num-1]] = key;
		arr[*list[list_num-1]+1] = NULL;
		arr[*list[list_num-1]+2] = NULL;

		printf("SUCCESSFULLY INSERTED IN SORTED ORDER\n");
	}
	else
	{
		int i=0;
		while(arr[3*i] != NULL)
		{
			i = i+1;
		}
		arr[3*i] = malloc(sizeof(int)); // allocate memory for the node of a list in heap
		*arr[3*i] = key;
		//arr[3*i+1] = NULL;

		*q = 3*(i+1);
		

		//Following part insert set next and prev of nodes so that element will be sorted
		int j = *list[list_num-1];
		while(key >= *arr[j])
		{
			if(arr[j+1] != NULL)
				j = *arr[j+1];
			else 
				break;
		}
		if(key>=*arr[j] && arr[j+1] == NULL && arr[j+2] != NULL) //i.e if j represent the last node
		{
			arr[3*i+1] = NULL;
			arr[3*i+2] = malloc(sizeof(int));
			*arr[3*i+2] = j;
			arr[j+1] = malloc(sizeof(int));
			*arr[j+1] = 3*i;
		}
		if(key< *arr[j] && arr[j+1] == NULL && arr[j+2] != NULL) //i.e if j represent the last node
		{
			arr[3*i+1] = malloc(sizeof(int));
			*arr[3*i+1] = j;
			arr[3*i+2] = malloc(sizeof(int));
			*arr[3*i+2] = *arr[j+2];
			*arr[*arr[j+2]+1] = 3*i;  
			*arr[j+2] = 3*i;
		}
		else if(key<*arr[j] && arr[j+2] == NULL && arr[j+2] == NULL)
		{	
			arr[3*i+1] = malloc(sizeof(int));
			*arr[3*i+1] = j;
			arr[3*i+2] = NULL;
			arr[j+2] = malloc(sizeof(int));
			*arr[j+2] = 3*i;
			*list[list_num-1] = 3*i;
		}
		else if(key>=*arr[j] && arr[j+2] == NULL && arr[j+2] == NULL)
		{	
			arr[3*i+1] = NULL;
			arr[j+1] = malloc(sizeof(int));
			arr[3*i+2] = malloc(sizeof(int));
			*arr[3*i+2] = j;
			*arr[j+1] = 3*i;
		}
		else
		{
			int temp = *arr[j+2];
			arr[3*i+1] = malloc(sizeof(int));
			*arr[3*i+1] = j;
			arr[3*i+2] = malloc(sizeof(int));
			*arr[3*i+2] = *arr[j+2];
			*arr[j+2] = 3*i;
			*arr[temp + 1] = 3*i;
		}
		if(arr[3*i] != NULL)
			printf("SUCCESSFULLY INSERTED IN SORTED ORDER\n");
		else
			printf("FAILURE: MEMORY NOT AVAILABLE\n");

	}
	
	
}


void deleteElement()
{
	printf("List you want to delete from: \n");
	int list_num;
	scanf("%d",&list_num);

	printf("Enter the key value: \n");
	int key;
	scanf("%d",&key);
	

	int flag = 0;

	int count = 0;
	int k = *list[list_num-1]+1;
	while(arr[k] != NULL)
	{
		count++;
		k = *arr[k]+1;
	}
	if(arr[k+1]!=NULL)
		count++;
	else if(arr[k+1] == NULL && arr[k-1] != NULL)
		count++;

	int j = *list[list_num-1]+1;  //set j to the next value of the head node
	while(arr[j] != NULL)
	{
		if(*arr[j-1] == key)
		{
			if(arr[j+1] == NULL)  // if the key is for head of the list
			{	
				arr[*arr[j]+2] = NULL ;  //make the prev of new head node to be null
				*list[list_num-1] = *arr[j];  //store the new list head in the list array
				arr[j-1] = NULL;
				arr[j] = NULL;
				arr[j+1] = NULL;
				
				arr[j] = malloc(sizeof(int));
				*arr[j] = *q;
				*q = j-1;
				flag = 1;
				break;
			}
			else
			{
				*arr[*arr[j+1]+1] = *arr[j];  //set the next pointer of the previous node
				*arr[*arr[j]+2] = *arr[j+1];  //set the prev pointer of the next node
				arr[j-1] = NULL;
				arr[j] = NULL;
				arr[j+1] = NULL;
				
				arr[j] = malloc(sizeof(int));
				*arr[j] = *q;
				*q = j-1;
				flag = 1;
				break;
			}
			
		}
		j = *arr[j]+1;
	}
	

	if(count == 1 && *arr[j-1] == key)
	{
		if(arr[j+1] == NULL)  // if the key is for head of the list and it's the only node in list
		{

			arr[j-1] = NULL;
				
				
			flag = 1;
		}
	}
	else if(count != 1 && arr[j-1] != NULL && *arr[j-1]==key)
	{

		arr[*arr[j+1]+1] = NULL;  //set the next pointer of the previous node
		//*arr[*arr[j]+2] = *arr[j+1];  //set the prev pointer of the next node
		arr[j-1] = NULL;
		arr[j] = NULL;
		arr[j+1] = NULL;
		
		arr[j] = malloc(sizeof(int));
		*arr[j] = *q;
		*q = j-1;
		flag = 1;
			
	}

	if(flag == 0)
		printf("FAILURE: ELEMENT NOT THERE.\n");
	else
		printf("SUCCESSFULLY DELETED THE ELEMENT FROM THE REQUIRED LIST\n");
}


void countTotalElements()
{
	
	printf("Total number of nodes in all lists are %d\n",countElements() );

}


void countTotalElementsOfList()
{
	printf("Enter the list number: \n");
	int list_num;
	scanf("%d",&list_num);
	printf("Total number of nodes in list %d are %d\n",list_num,elementsOfList(list_num) );
}



void displayLists()
{
	int i = 0;
	while(list[i] != NULL)
	{
		int head = *list[i];
		int j = head + 1;
		//Following  8 lines count the number of nodes in list i
		int count = 0;
		int k = head + 1;
		while(arr[k] != NULL)
		{
			count++;
			k = *arr[k]+1;
		}
		if(arr[k+1]!=NULL)
			count++;
		else if(arr[k+1] == NULL && arr[k-1] != NULL)
			count++;
		printf("Elements of list-%d are:\nkey \t next \t prev\n",i+1 );
		
		if(count == 0)
			printf("List %d is empty \n",i+1 );

		
		
		else if(count == 1)
			printf("%d \t %s \t %s \n\n",*arr[j-1],"NIL","NIL" );
		else
		{	
			printf("%d \t %d \t %s \n",*arr[j-1],*arr[j],"NIL" );   //printing the first node
			//printf("%d\n",count1);
			j = *arr[j] + 1;
			while(arr[j] != NULL)
			{
				printf("%d \t %d \t %d\n",*arr[j-1],*arr[j],*arr[j+1] );
				j = *arr[j]+1;
			}
			printf("%d \t %s \t %d \n\n",*arr[j-1],"NIL",*arr[j+1] );  //printing the last node
		
		}
		
		i = i+1;
			
	}
}


void displayFreeList()
{
	printf("Elements of free list are:\n[");
	int i = *q + 1;
	while(arr[i] != NULL)
	{
		printf("%d,",i-1 );
		i = *arr[i] + 1;
	}
	printf("%d ]\n",i-1 );

}

void exitOnCall()
{
	exit(0);
}

void performDefragmentation()
{
	int total = countElements();
	int mat[total];
	int i=0;
	int key=0;
	while(list[i] != NULL)
	{
		int j = *list[i]+1;
		
		while(arr[j] != NULL)
		{
			mat[key] = *arr[j-1];
			key++;
			j = *arr[j]+1;
		}
		mat[key] = *arr[j-1];
		key++;
		i++;
	}
	
	
	for(int k=0; k<total; k++)
	{
		if(arr[3*k] == NULL)
		{
			//arr[3*k+1] = malloc(sizeof(int));
			//arr[3*k+2] = malloc(sizeof(int));
			arr[3*k] = malloc(sizeof(int));
		}
	}//
	int mark=0;
	for(int k=1; k<=numberOfList(); k++)
	{
		for(int l=0; l<elementsOfList(k); l++)
		{	
			arr[3*mark] = malloc(sizeof(int));
			*arr[3*mark] = mat[mark];
			
			if( l != 0 )
			{	
				arr[3*mark+2] = malloc(sizeof(int));
				*arr[3*mark+2] = 3*(mark-1);
			}
			
			if(l == 0)
			{
				arr[3*mark+2] = NULL;
				*list[k-1] = 3*mark;
			}
			if(l != elementsOfList(k)-1)
			{
				arr[3*mark+1] = malloc(sizeof(int));
				*arr[3*mark+1] = 3*(mark+1);
			}
			if(l == elementsOfList(k)-1)
			{
				arr[3*mark+1] = NULL;
			}
			mark++;
		}
	}
	
	*q = 3*(total);
	for(int z=total; z<332; z++)
	{
		if(arr[3*z+1]==NULL)
		{
			arr[3*z+1] = malloc(sizeof(int));
			*arr[3*z+1] = 3*(z+1);
		}
		else
			*arr[3*z+1] = 3*(z+1);
	}

	printf("SUCCESS IN DEFRAGMENTATION. \n THE FREE LIST INDEX HAVE BEEN ARRANGED SEQUENTIALLY\n");
}

int countElements()
{
	int i=0,count = 0;
	while(list[i] != NULL)
	{
		int head = *list[i];
		int j = head + 1;
		while(arr[j] != NULL)
		{
			count++;
			j = *arr[j]+1;
		}
		if(arr[j+1]!=NULL)
			count++;
		else if(arr[j+1] == NULL && arr[j-1] != NULL)
			count++;
		i++;
	} //END of while loop
	return count;

}

int elementsOfList(int list_num)
{
	int count = 0;
	int j = *list[list_num-1]+1;
	while(arr[j] != NULL)
	{
		count++;
		j = *arr[j]+1;
	}
	if(arr[j+1]!=NULL)
		count++;
	else if(arr[j+1] == NULL && arr[j-1] != NULL)
		count++;
	return count;
}

int numberOfList()
{
	int count=0;
	int i=0;
	while(list[i] != NULL)
	{
		count++;
		i++;
	}
	//printf("%d\n",count );
	return count;
}

