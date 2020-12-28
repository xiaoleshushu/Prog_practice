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

