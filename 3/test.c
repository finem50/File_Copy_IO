#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dslib.h"


int main(){
	
	int i, j = 0, set_size, stack_input[1000] = {};
	char choice[10];
	stack new_stack;

	printf("Welcome!\nEnter the desired stack size:\n");
	scanf("%d", &set_size);
	stack_init(&new_stack, set_size);

	while(strcmp(choice, "quit")){
		
		printf("\nType 'push', 'pop', 'size' or 'quit' for your desired action: ");
		scanf("%s", choice);
		
		if(!strcmp(choice, "push")){
	
			printf("Enter an integer to push onto the stack: ");
			scanf("%d", stack_input);
			stack_push(&new_stack, stack_input[j]);
			j++;
		}else if(!strcmp(choice, "pop")){
			
			printf("POP!: %d\n", stack_pop(&new_stack));
		}else if(!strcmp(choice, "size")){

			printf("Stack size: %d\n", stack_size(&new_stack));
		}else{
			
			if(!strcmp(choice, "quit")){

				break;
			}else{
				printf("Invalid input!\n");
				continue;
			}
		}
	}
	
	stack_deallocate(&new_stack);

	printf("The stack is dead! Long live the stack!\n");

	return 0;
}
