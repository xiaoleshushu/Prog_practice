/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"

/* external function */

/* local */
//STACK *stack;


int main(int argc, char *argv[])
{
	int rc = -1;
	TREE_NODE root;

	/*init stack*/
	INIT_STACK(g_stack);
	
	/*init tree*/
	build_bi_tree(&root, 3);
	/*先序遍历二叉树*/
	printf("先序遍历-递归：\n");
	pre_order_traveral(&root);
	printf("先序遍历-非递归：\n");
	pre_order_traveral2(&root);
	/*改进的非递归先序遍历*/
	printf("先序遍历-非递归改进：\n");
	pre_order_traveral3(&root);

	/*中序遍历二叉树*/
	printf("中序遍历-递归：\n");
	mid_order_traveral(&root);
	printf("中序遍历-非递归：\n");
	mid_order_traveral2(&root);

	/*中序遍历二叉树*/
	printf("后序遍历-递归：\n");
	post_order_traveral(&root);
	printf("后序遍历-非递归：\n");
	post_order_traveral2(&root);

	return rc;

}
