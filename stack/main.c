/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"
//#define TEST_STACK_FUNC
//#define TEST_STACK_SORT
#define TEST_HANOI_TOW

/* external function */
extern int stack_empty(STACK *stack);
extern int stack_full(STACK *stack);
extern int stack_top(STACK *stack);
extern int stack_push(STACK *stack, int data);
extern int stack_pop(STACK *stack);
extern void print_stack(STACK *stack);
extern int stack_depth(STACK *stack);
extern void sort_stack(STACK *stack);
extern void towers_of_hanoi(STACK *a, STACK *b, STACK *c);

/* local function */
void test_stack(STACK *stack)
{
	int i;

	if (stack == NULL)
		return;
	printf("init stack, depth = %d\n", stack_depth(stack));
	print_stack(stack);
	printf("stack empty? %d\n", stack_empty(stack));
	for (i=0; i<stack_depth(stack); i++)
		stack_push(stack, i);
	printf("stack full? %d\n", stack_full(stack));
	printf("stack top = %d\n", stack_top(stack));
	i = stack_pop(stack);
	printf("stack pop : %d\n", i);
	printf("now stack :\n");
	print_stack(stack);
	
	return;
}
/*fill stack with random number*/
void fill_stack_random(STACK *stack)
{
	if (stack == NULL)
		return;
	while (!stack_empty(stack))
		stack_pop(stack);
	while (!stack_full(stack))
		stack_push(stack, rand()%16);

	return;
}

void init_stack(STACK *stack)
{
	if (stack == NULL)
		return;
	memset(stack->data, 0, STACK_DEPTH*sizeof(int));
	stack->top = 0;
	stack->point = 0;
	stack->depth = STACK_DEPTH;
}

int main(int argc, char *argv[])
{
	int rc = -1;

	STACK *stack;
	INIT_STACK(stack);
#ifdef TEST_STACK_FUNC
	/*test stack ops*/
	test_stack(stack);
#endif
#ifdef TEST_STACK_SORT
	/*fill stack with random number*/
	fill_stack_random(stack);
	print_stack(stack);

	/*test stack sort*/
	sort_stack(stack);
#endif
#ifdef TEST_HANOI_TOW
	/*test towers_of_hanoi*/
	STACK a;
	STACK b;
	STACK c;
	init_stack(&a);
	init_stack(&b);
	init_stack(&c);
	fill_stack_random(&a);
	towers_of_hanoi(&a, &b, &c);
#endif

	return rc;

}
