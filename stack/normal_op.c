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
int stack_pop(STACK *stack, int *data)
{
	int rc;

	if (stack && !stack_empty(stack)) {
		*data = stack->top;
		stack->data[stack->point-1] = 0;
		stack->point--;
		stack->top = data[stack->point-1];
		rc = 0;
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
