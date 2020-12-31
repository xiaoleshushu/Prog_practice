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
#define STACK_DEPTH	16

typedef struct stack {
	int data[STACK_DEPTH];
	int top;
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

