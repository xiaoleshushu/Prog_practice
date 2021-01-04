/*******************************
 *
 * binary tree funcs
 *
 ******************************/
#include "public.h"
#define DEPTH_TREE	4
int g_depth = 0;
int g_data = 0;

/*build a tree*/
/*随便创建一个深度指定的二叉树用于测试*/
static int random_juge(void)
{
	//return rand()%2;
	return 1;
}
void build_bi_tree(TREE_NODE *root,int depth)
{
	TREE_NODE *left;
	TREE_NODE *right;

	if (root == NULL || depth < 1)
		return;
	g_depth++;
	if (g_depth >= depth) {
		printf("depth = %d \n", g_depth);
		g_depth--;
		return;
	}
	/*随机判断是否建立左节点*/
	if (random_juge()) {
		left = (TREE_NODE *)malloc(sizeof(TREE_NODE *));
		left->left = NULL;
		left->right = NULL;
		root->left = left;
		//left->data = rand()%16;
		left->data = g_data++;
		build_bi_tree(left, depth);
	
	}
	/*随机判断是否建立右节点*/
	if (random_juge()) {
		right = (TREE_NODE *)malloc(sizeof(TREE_NODE *));
		right->left = NULL;
		right->right = NULL;
		root->right = right;
		//right->data = rand()%16;
		right->data = g_data++;
		build_bi_tree(right, depth);
	}
	
	g_depth--;
	return;
}

/*先序遍历二叉树 - 递归方式*/
void pre_order_traveral(TREE_NODE *root)
{
	if (root == NULL)
		return;
	printf("root->data %d\n", root->data);
	pre_order_traveral(root->left);
	pre_order_traveral(root->right);
	
	return;
}
/*先序遍历二叉树 - 非递归方式*/
void pre_order_traveral2(TREE_NODE *root)
{
	TREE_NODE *tmp;

	if (root == NULL)
		return;
	tmp = root;
	while (tmp || !stack_empty()) {
		/*1.先访问父节点*/
		printf("data = %d\n", tmp->data);
		/*2.然后访问左节点*/
		if (tmp && tmp->left) {
			stack_push(tmp);
			tmp = tmp->left;
			continue;
		}
		/*3.最后访问右节点*/
		if (tmp && tmp->right) {
			stack_push(tmp);
			tmp = tmp->right;
			continue;
		}
		if (!stack_empty()) {
			tmp = stack_pop();
			tmp = tmp->right;
		}
		else
			break;
	}	
}
/*改进*/
/*pre_order_traveral2太乱，不够简约*/
void pre_order_traveral3(TREE_NODE *root)
{
	TREE_NODE *tmp;

	if (root == NULL)
		return;
	tmp = root;
	while (tmp || !stack_empty()) {
		while (tmp) {
			/*1.访问所有的左节点*/
			printf("data = %d\n", tmp->data);
			stack_push(tmp);
			tmp = tmp->left;
		}
		/*2.出栈 先序遍历最近一个节点的右节点*/
		if (!stack_empty()) {
			tmp = stack_pop();
			tmp = tmp->right;
		}
	}
}

/*中序遍历二叉树 - 递归方式*/
void mid_order_traveral(TREE_NODE *root)
{
	if (root == NULL)
		return;
	mid_order_traveral(root->left);
	printf("root->data = %d\n", root->data);
	mid_order_traveral(root->right);
}

/*中序遍历二叉树 - 非递归方式*/
void mid_order_traveral2(TREE_NODE *root)
{
	TREE_NODE *tmp;

	if (root == NULL)
		return;
	tmp = root;
	while (tmp || !stack_empty()) {
		while (tmp) {
			/*1.找到最左的节点*/
			stack_push(tmp);
			tmp = tmp->left;
		}
		if (!stack_empty()) {
			/*2.出栈 访问最左节点，并中序遍历他的右节点*/
			tmp = stack_pop();
			printf("data = %d\n", tmp->data);
			tmp = tmp->right;
		}
	}
}

/*后序遍历二叉树 - 递归方式*/
void post_order_traveral(TREE_NODE *root)
{
	if (root == NULL)
		return;
	post_order_traveral(root->left);
	post_order_traveral(root->right);
	printf("root->data = %d\n", root->data);
}

/*后序遍历二叉树 - 非递归方式*/
void post_order_traveral2(TREE_NODE *root)
{
	TREE_NODE *tmp;
	TREE_NODE *last_node = NULL;

	if (root == NULL)
		return;
	tmp = root;
	while (tmp || !stack_empty()) {
		while (tmp) {
			/*1.先找到最左节点*/
			stack_push(tmp);
			tmp = tmp->left;
		}
		if (!stack_empty()) {
			/*2.后序遍历栈中节点*/
			tmp = stack_pop();
			/*2.1当右节点为空，或者刚刚访问了右节点，则访问此父节点*/
			if (tmp->right == NULL || last_node == tmp->right) {
				printf("data = %d\n", tmp->data);
				last_node = tmp;
				tmp = NULL;
			} else {
				/*2.2否则后续遍历右节点*/
				stack_push(tmp);
				tmp = tmp->right;
			}
		}
	}
}

/*层序遍历二叉树 - 队列*/
/*队列queue数据结构和函数没实现，暂时关闭这个函数*/
#if 0
void level_order_traveral(TREE_NODE *root)
{
	if (root == NULL)
		return;
	tmp = root;
	queue_push(tmp);
	while (!queue_empty()) {
		tmp = queue_pop();
		printf("data = %d\n", tmp->data);
		if (queue_empty()) {
			if (tmp->left)
				queue_push(tmp->left);
			if (tmp->right)
				queue_push(tmp->right);
		}
	}
}
#endif
