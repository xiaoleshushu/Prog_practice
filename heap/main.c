/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"

/* external function */
extern void build_heap_big(int *heap, int length);
extern void print_heap(int *heap, int len);

int main(int argc, char *argv[])
{
	//int i;
	int rc = -1;
	int heap[] = {4,1,3,1,9,40,0};

	print_heap(heap, sizeof(heap)/sizeof(int));
	build_heap_big(heap, sizeof(heap)/sizeof(int));
	print_heap(heap, sizeof(heap)/sizeof(int));

	return rc;

}
