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
