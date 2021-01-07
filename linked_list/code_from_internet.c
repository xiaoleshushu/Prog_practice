/**********************************
 *
 *  leecode或者其他来源的链表题目
 *
 *********************************/

#include "public.h"

/* [1].There's a number array, swparate it into digits and 
 * create a double-linked list based no these digits. 
 * e.g. __    ________    _____
 *     |  v  |        v  v     v
 *     1<-3  4<-5<-2<-6  7<-8<-9
 *   ->1->3->4->5->2->6->7->8->9->null , stands for 13,4526,789
 *
 * */
DIGIT_NODE *array_to_dlist(int *array, int count)
{
	int i;
	int num, digit;
	DIGIT_NODE *head = NULL;
	DIGIT_NODE *new = NULL;
	DIGIT_NODE *tmp = NULL;
	DIGIT_NODE *tail = NULL;

	if (array == NULL || count < 1)
		return NULL;
	/*init head*/
	head = (DIGIT_NODE *)malloc(sizeof(DIGIT_NODE));
	if (!head)
		return NULL;
	head->prev = NULL;
	head->next = NULL;
	for (i=count-1; i>=0; i--) {
		num = array[i];
		while(num) {
			digit = num%10;
			num = num/10;
			new = (DIGIT_NODE *)malloc(sizeof(DIGIT_NODE));
			if (!head)
				goto free_list;
			new->val = digit;
			tmp = head->next;
			head->next = new;
			new->next = tmp;
			if (tail)
				tmp->prev = new;
			if (!tail)
				tail = new;
		}
		head->next->prev = tail;
		tail = NULL;
	}

	return head;
free_list:
	printf("malloc list node failed, now free alloced node\n");
	while(head->next) {
		tmp = head->next;
		head->next = tmp->next;
		free(tmp);
	}
	return NULL;
}
