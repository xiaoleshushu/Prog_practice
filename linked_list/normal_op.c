/****************************
 *
 * normal operation of linked list
 *
*****************************/
#include "public.h"




/*删除链表倒数第N个节点*/
struct list_node* delete_bottom_n(struct list_node* head, int n)
{
	int tmp = 0;
	struct list_node* first = head;
	struct list_node* del = NULL;

	if (head == NULL || n <= 0)
		return NULL;
	while (first->next) {
		if (tmp == n) 
			del = head;
		if (del)
			del = del->next;
		first = first->next;
		tmp++;
	}
	/*delete del->next*/
	first = del->next;
	printf("first->data = %ld \n", first->data);
	if (first)
		del->next = first->next;
	
	return first;
}
