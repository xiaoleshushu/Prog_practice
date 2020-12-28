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

/*单链表反转一：头插法*/
struct list_node* reverse_list(struct list_node* head)
{
	struct list_node new_node;
	struct list_node *new_head = &new_node;
	struct list_node* tmp = head;

	if (head == NULL || head->next == NULL)
		return head;
	new_head->next = NULL;
	while (tmp) {
		tmp = head->next;
		head->next = new_head->next;
		new_head->next = head;
		head = tmp;
	}
	
	return new_head->next;
}

/*单链表反转一：原地倒置法*/
struct list_node* reverse_list2(struct list_node* head)
{
	struct list_node* tmp = head;
	struct list_node* next = NULL;

	if (head == NULL || head->next == NULL)
		return head;
	while (tmp->next) {
		next = tmp->next;
		tmp->next = next->next;
		next->next = head;
		head = next;
		//tmp = tmp->next;
	}
	return head;
}

/*删除链表中指定元素*/
struct list_node* delete_node(struct list_node** head, long val)
{
	struct list_node* father = *head;
	struct list_node* next = NULL;

	if (head == NULL || *head == NULL)
		return *head;
	if ((*head)->data == val) {
		*head = (*head)->next;
		return father;
	}
	next = father->next;
	while (next) {
		if (next->data == val) {
			father->next = next->next;
			break;
		}
		father = next;
		next = next->next;
	}

	return next;
}
