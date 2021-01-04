/***************************
 *
 *  public header
 *
 **************************/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define STACK_DEPTH     16


typedef struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
}TREE_NODE;


typedef struct stack {
	TREE_NODE *data[STACK_DEPTH];
	TREE_NODE *top;
	int point; /*位置指针*/
	int depth;
	//int reserved;
}STACK;

#define INIT_STACK(v) \
	STACK x; \
	memset(x.data, 0, STACK_DEPTH*sizeof(int)); \
	x.top = 0; \
	x.point = 0; \
	x.depth = STACK_DEPTH; \
	v = &x;

/* global stack */
STACK *g_stack;


/* external function */
int stack_empty(void);
int stack_full(void);
int stack_push(TREE_NODE * node);
TREE_NODE * stack_top(void);
TREE_NODE *stack_pop(void);
int stack_depth(void);

void build_bi_tree(TREE_NODE *root,int depth);
void pre_order_traveral(TREE_NODE *root);
void pre_order_traveral2(TREE_NODE *root);
void pre_order_traveral3(TREE_NODE *root);
void mid_order_traveral(TREE_NODE *root);
void mid_order_traveral2(TREE_NODE *root);
void post_order_traveral(TREE_NODE *root);
void post_order_traveral2(TREE_NODE *root);
