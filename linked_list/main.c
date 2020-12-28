/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"
#define	LIST_LEN	16

/* external function */
extern struct list_node* delete_bottom_n(struct list_node* head, int n);

/* local function */
void print_list_local(struct list_node* head)
{
	struct list_node* next = head;

	printf("list: \n");
	while (next) {
		printf("%ld ", next->data);
		next = next->next;
	}
	printf("\n\n");
}

int main(int argc, char *argv[])
{
	int i;
	int rc = 0;
	struct list_node* head;
	struct list_node* next;

	/* init list */
	head = (struct list_node*)malloc(sizeof(struct list_node));
	if (!head)
		return -1;
	head->data = 0x1111; /*head magic*/
	for (i=0; i<LIST_LEN; i++) {
		next = (struct list_node*)malloc(sizeof(struct list_node));
		if (!next)
			goto free_list;
		next->data = i+1;
		next->next = head->next;
		head->next = next;
	}
	print_list_local(head);

	/* test delete_bottom_n */
	next = delete_bottom_n(head, 3);
	if (next)
		printf("test delete_bottom_n: del->data = %ld\n", next->data);
	else
		printf("delete_bottom_n return NULL !!!!\n");
	print_list_local(head);
	if (next)
		free(next);

free_list:
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
	return rc;
}
