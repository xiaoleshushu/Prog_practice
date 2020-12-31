/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"

/* external function */
extern int stack_empty(STACK *stack);
extern int stack_full(STACK *stack);
extern int stack_top(STACK *stack);
extern int stack_push(STACK *stack, int data);
extern int stack_pop(STACK *stack, int *data);
extern void print_stack(STACK *stack);
extern int stack_depth(STACK *stack);

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
	stack_pop(stack, &i);
	printf("stack pop : %d\n", i);
	printf("now stack :\n");
	print_stack(stack);
	
	return;
}

int main(int argc, char *argv[])
{
	//int i;
	int rc = -1;

	STACK *stack;
	INIT_STACK(stack);

	/*test stack ops*/
	test_stack(stack);
	
	return rc;

}
