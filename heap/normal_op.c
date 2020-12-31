/*******************************
 *
 * heap ops funcs
 * 仅限于大顶堆
 *
 ******************************/
#include "public.h"

/*
 *
 * 大顶堆需要满足父节点大于所有子节点
 *
 */

void print_heap(int *heap, int len)
{
	int i;

	if (heap == NULL || len < 1)
		return;
	for (i=0; i<len; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

/*根据大顶堆规则，调整父节点i 和子节点的位置*/
/*length用于判断是否有子节点*/
static void adjust_arry_big(int *heap, int i, int length)
{
	int tmp;
	int bigger;

	/*找到子节点更大的那一个*/
	if (length > i*2+2) {
		/*两个子节点*/
		if (heap[i*2+1] > heap[i*2+2])
			bigger = i*2+1;
		else
			bigger = i*2+2;
	} else {
		bigger = i*2+1;
	}

	/*调整父节点位置*/
	if (heap[i] > heap[bigger])
		return;
	else {
		tmp = heap[i];
		heap[i] = heap[bigger];
		heap[bigger] = tmp;
	}

	return;
}

/* 构建大顶堆 */
/*
 * 输入：无序数组和数组程度
 * 输出：大顶堆
 */
void build_heap_big(int *heap, int length)
{
	int i;

	if (heap == NULL || length <= 1)
		return;
	/* 从最后一个非叶子节点,从下至上，从右至左调整“二叉树” */
	for (i = length/2-1; i >= 0; i--)
		adjust_arry_big(heap, i, length);
	
	return;
}

