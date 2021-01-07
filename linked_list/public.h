/***************************
 *
 *  public header
 *
 **************************/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*链表数据结构*/
struct list_node {
	long data;
	struct list_node *next;
};

/*双向链表数据结构*/
typedef struct node {
	int val;
	struct node *prev;
	struct node *next;
} DIGIT_NODE;

