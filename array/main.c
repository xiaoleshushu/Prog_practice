/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"
#define	LIST_LEN	16

/* external function */
extern int find_arry_center(int *arry, int len);


int main(int argc, char *argv[])
{
	//int i;
	int rc = -1;
	int arry[] = {1,2,3,5,3,2,1};
	
	/* test find_arry_center */
	rc = find_arry_center(arry, sizeof(arry)/sizeof(int));
	if (rc < 0)
		printf("there is no center in this arry! \n");
	else
		printf("center index = %d\n", rc);

	return rc;
}
