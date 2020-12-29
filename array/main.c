/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"
#define	LIST_LEN	16
//#define TEST_FIND_ARRY_CENTER
//#define TEST_YANGHUI_TRI
#define TEST_ARRY_ROTATE

/* external function */
extern int find_arry_center(int *arry, int len);
extern int yanghui_triangle(int line);
extern int rotate(int *arry, int cnt, int k);
extern void print_arry_int(int *arry, int cnt);
int main(int argc, char *argv[])
{
	//int i;
	int rc = -1;
	int arry[] = {1,2,3,5,3,2,1};

#ifdef TEST_FIND_ARRY_CENTER
	/* test find_arry_center */
	rc = find_arry_center(arry, sizeof(arry)/sizeof(int));
	if (rc < 0)
		printf("there is no center in this arry! \n");
	else
		printf("center index = %d\n", rc);
#endif
#ifdef TEST_YANGHUI_TRI
	/*test yanghui_triangle*/
	for (i=0; i<6; i++) {
		printf("test: line = %d\n", i);
		rc = yanghui_triangle(i);
		if (rc < 0)
			printf("error! \n");
	}
#endif
#ifdef TEST_ARRY_ROTATE
	/*test rotate*/
	print_arry_int(arry, 7);
	rc = rotate(arry, 7, 10);
	if (rc < 0)
		printf("error! \n");
	else
		print_arry_int(arry, 7);	
#endif
	return rc;

}
