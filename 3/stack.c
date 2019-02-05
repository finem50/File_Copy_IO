#include "dslib.h"
#include <stdlib.h>
#include <stdio.h>


void stack_init(stack *s, int capacity){

	number_stack *num_in;
	num_in = (number_stack *) malloc(sizeof(number_stack) * capacity);

	(*s).nums = num_in;
	(*s).max_cap = capacity;
	// -1 used to indicate that top is empty
	(*s).top = -1;
}


int stack_size(stack *s){

	int size = 0, i;
	for(i = 0; i <= (*s).top; i++){

		//Add 1 to size counter for every int less than top
		size += 1;
	}

	return size;
}


int stack_pop(stack *s){

	//If stack is empty, do nothing
	if ((*s).top < 0){

		printf("The stack is empty!\n");
		return -999;
	}else {
		
		//Otherwise, remove one number from top of stack
		return (*s).nums[(*s).top--];
	}

}


void stack_push(stack *s, int e){

	//If stack is full, do nothing
	if ((*s).top > (*s).max_cap){

		printf("The stack is full!\n");
		exit(1);
	}

	//Otherwise, add number to stack
	(*s).nums[(*s).top += 1] = e;
}


void stack_deallocate(stack *s){

	free((*s).nums); //Release integers from stack
	(*s).nums = NULL;
	(*s).max_cap = 0; //Clear the stack capacity
	(*s).top = -1; //Return state of top to empty 
}

