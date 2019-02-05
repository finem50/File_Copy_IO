#ifndef DSLIB_H
#define DSLIB_H

typedef int number_stack;

typedef struct stackTag{

	number_stack *nums;
	int max_cap;
	int top;
}stack;

void stack_init(stack *s, int capacity);

int stack_size(stack *s);

int stack_pop(stack *s);

void stack_push(stack *s, int e);

void stack_deallocate(stack *s);

#endif
