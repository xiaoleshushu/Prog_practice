/*******************************
 *
 * array ops funcs
 *
 ******************************/
#include "public.h"

/* 栈ops函数实现 */
int stack_empty(STACK *stack)
{
	if (stack == NULL)
		return 0;
	return (stack->point == 0)?(1):(0);
}
int stack_full(STACK *stack)
{
	if (stack == NULL)
		return 0;
	return (stack->point == stack->depth)?(1):(0);
}

int stack_top(STACK *stack)
{
	if (stack)
		return stack->top;
	else
		return -1; /*数据也可能是-1？*/
}
int stack_depth(STACK *stack)
{
	if (stack)
		return stack->depth;
	else
		return -1;
}
int stack_push(STACK *stack, int data)
{
	if (stack && !stack_full(stack)) {
		stack->data[stack->point] = data;
		stack->point++;
		stack->top = data;
		return 0;
	} else {
		return -1;
	}
}
int stack_pop(STACK *stack)
{
	int rc;

	if (stack && !stack_empty(stack)) {
		rc = stack->top;
		stack->data[stack->point-1] = 0;
		stack->point--;
		stack->top = stack->data[stack->point-1];
		//rc = 0;
	} else {
		rc = -1;
	}
	return rc;
}
void print_stack(STACK *stack)
{
	int i;

	if (stack) {
		if (stack_empty(stack)) {
			printf("stack is empty!!!\n");
			return;
		}
		for (i=0; i<stack->point; i++)
			printf("%d ", stack->data[i]);
	}
	printf("\n");

	return;
}


/*
 *
 * 栈排序：递增
 * 要求最多只能使用一个额外的栈存放临时数据，
 * 但不得将元素复制到别的数据结构中
 *
 */
void sort_stack(STACK *stack)
{
	STACK *new_stack;
	int tmp = 0;

	if (stack == NULL || stack_depth(stack) <= 1)
		return;
	/*create a new stack for data moving*/
	INIT_STACK(new_stack);
	stack_push(new_stack, stack_pop(stack));
	while (!stack_empty(stack)) {
		if (stack_top(stack) <= stack_top(new_stack))
			stack_push(new_stack, stack_pop(stack));
		else {
			tmp = stack_pop(stack);
			stack_push(stack, stack_pop(new_stack));
			stack_push(stack, tmp);
		}
	}
	print_stack(new_stack); //debug
	
	/*move all data to origon stack*/
	while (!stack_empty(new_stack)) {
		stack_push(stack, stack_pop(new_stack));
	}
	print_stack(stack);

	return;
}


