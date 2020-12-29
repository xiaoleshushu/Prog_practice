/*******************************
 *
 * array ops funcs
 *
 ******************************/
#include "public.h"

/*找数组中心索引，即前后和相等*/
int find_arry_center(int *arry, int len)
{
	int index, i;
	long sum, sum_left;

	if (arry == NULL || len <= 0)
		return 0;
	printf("[debug]: len = %d\n", len);
	/*arry sum*/
	for (i=0; i<len; i++)
		sum += arry[i];
	sum_left = 0;
	for (i=0; i<len; i++) {
		if (sum == sum_left*2 + arry[i]) {
			index = i;
			break;
		}
		sum_left += arry[i];
	}

	return index;
}

/*打印数组*/
void print_arry_int(int *arry, int cnt)
{
	int i;
	
	for (i=0; i<cnt; i++) 
		printf("%d ", arry[i]);
	printf("\n");
}

/*杨辉三角*/
/*
 *   1
 *  1 1
 * 1 2 1
 *1 3 3 1
 1 4 6 4 1
 *
 */
/*返回杨辉三角指定行-循环实现*/
/* 疑问：数组长度不支持变量怎么办？ */
int yanghui_triangle(int line)
{
	int tri[line];
	int i, j;

	if (line <= 0)
		return -1;
	tri[0] = 1;
	for (i=1; i<line; i++) {
		tri[i] = 1;
		for (j=i-1; j>0; j--) {
			tri[j] = tri[j] + tri[j-1];
		}
	}
	print_arry_int(tri, line);
	return 0;
}

/*数组反转*/
int reverse(int *arry, int cnt)
{
	int i, tmp;

	if (arry == NULL || cnt <= 0)
		return -1;
	if (cnt == 1)
		return 0;

	for (i=0; i<cnt/2; i++) {
		tmp = arry[cnt-1-i];
		arry[cnt-1-i] = arry[i];
		arry[i] = tmp;
	}
	return 0;
}

/*数组旋转*/
/*
 * 将数组中的元素向右移动 k 个位置，其中 k 是非负数
 *
 * 解题：先反转前N-K个，再反转后K个，最后反转整个数组，得到的就是旋转结果
 */
int rotate(int *arry, int cnt, int k)
{
	int rc = -1;

	if (arry == NULL || cnt <=0 || k < 0)
		return rc;
	/*算处最小移动数，k可能数倍于cnt*/
	k = k%cnt;
	if (k == 0) {
		rc = 0;
		return rc;
	}

	/*先反转前半部，再反转后半部，最后全部反转*/
	reverse(arry, cnt-k);
	reverse(arry+(cnt-k), k);
	reverse(arry, cnt);
	rc = 0;
	
	return rc;
}
