/*******************************
 *
 * stack ops funcs
 *
 ******************************/
#include "public.h"

/* 栈ops函数实现 */
int stack_empty(void)
{
	STACK *stack = g_stack;

	if (stack == NULL)
		return 0;
	return (stack->point == 0)?(1):(0);
}
int stack_full(void)
{
	STACK *stack = g_stack;

	if (stack == NULL)
		return 0;
	return (stack->point == stack->depth)?(1):(0);
}

TREE_NODE * stack_top(void)
{
	STACK *stack = g_stack;

	if (stack)
		return stack->top;
	else
		return NULL;
}
int stack_depth()
{
	STACK *stack = g_stack;

	if (stack)
		return stack->depth;
	else
		return -1;
}
int stack_push(TREE_NODE *node)
{
	STACK *stack = g_stack;

	if (stack && node && !stack_full()) {
		stack->data[stack->point] = node;
		stack->point++;
		stack->top = node;
		return 0;
	} else {
		return -1;
	}
}
TREE_NODE * stack_pop(void)
{
	TREE_NODE *rc;
	STACK *stack = g_stack;

	if (stack && !stack_empty()) {
		rc = stack->top;
		stack->data[stack->point-1] = NULL;
		stack->point--;
		stack->top = stack->data[stack->point-1];
	} else {
		rc = NULL;
	}
	return rc;
}
#if 0
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
#endif
