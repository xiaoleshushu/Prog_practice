/******************
 *
 *  main 文件
 *
 *****************/
#include "public.h"
#define	LIST_LEN	16
//#define TEST_DELETE_BOTTIOM_N
//#define TEST_REVERSE_LIST
//#define TEST_REVERSE_LIST2
//#define TEST_DELETE_NODE
#define TEST_DIGIT_LIST

/* external function */
extern struct list_node* delete_bottom_n(struct list_node* head, int n);
extern struct list_node* reverse_list(struct list_node* head);
extern struct list_node* reverse_list2(struct list_node* head);
extern struct list_node* delete_node(struct list_node** head, long val);
extern DIGIT_NODE *array_to_dlist(int *array, int count);

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
	//print_list_local(head);

#ifdef TEST_DELETE_BOTTIOM_N
	/* test delete_bottom_n */
	next = delete_bottom_n(head, 3);
	if (next)
		printf("test delete_bottom_n: del->data = %ld\n", next->data);
	else
		printf("delete_bottom_n return NULL !!!!\n");
	print_list_local(head);
	if (next)
		free(next);
#endif
#ifdef TEST_REVERSE_LIST
	/* test reverse_list */
	head = reverse_list(head);
	if (!head) {
		printf("reverse_list return NULL!!! \n");
		return -1;
	}
	print_list_local(head);
#endif
#ifdef TEST_REVERSE_LIST2
	/* test reverse_list */
	head = reverse_list2(head);
        if (!head) {
	        printf("reverse_list return NULL!!! \n");
		return -1;
	}
        print_list_local(head);	
#endif
#ifdef TEST_DELETE_NODE
	next = delete_node(&head, 12);
	print_list_local(head);
	if (next)
		free(next);
#endif
#ifdef TEST_DIGIT_LIST
	DIGIT_NODE *dhead = NULL;
	DIGIT_NODE *step = NULL;
	DIGIT_NODE *prev = NULL;
	int array[] = {13,4526,789};
	dhead = array_to_dlist(array, sizeof(array)/sizeof(int));
	if (!dhead) {
		printf("get head failed!!!\n");
		return -1;
	}
	/*debug dlist*/
	step = dhead->next;
	prev = dhead;
	while(step) {
		if (prev != step->prev)
			printf(" ");
		printf("%d", step->val);
		if (prev != step->prev && step->prev != NULL)
			printf("(%d)", step->prev->val);
		prev = step;
		step = step->next;
	}
	printf("\n");
#endif

free_list:
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
	return rc;
}
