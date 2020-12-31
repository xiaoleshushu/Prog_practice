/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"
//#define TEST_BUILD_HEAP
#define TEST_HEAP_SORT

/* external function */
extern void build_heap_big(int *heap, int length);
extern void print_heap(int *heap, int len);
extern void heap_sort_big_end(int *arry, int length);

int main(int argc, char *argv[])
{
	//int i;
	int rc = -1;
	int heap[] = {4,1,3,1,9,40,0};

#ifdef TEST_BUILD_HEAP
	print_heap(heap, sizeof(heap)/sizeof(int));
	build_heap_big(heap, sizeof(heap)/sizeof(int));
	print_heap(heap, sizeof(heap)/sizeof(int));
#endif
#ifdef TEST_HEAP_SORT
	print_heap(heap, sizeof(heap)/sizeof(int));
	heap_sort_big_end(heap, sizeof(heap)/sizeof(int));
	print_heap(heap, sizeof(heap)/sizeof(int));

#endif
	return rc;

}
