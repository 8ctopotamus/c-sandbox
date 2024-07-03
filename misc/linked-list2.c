// https://learn-c.org/en/Linked_lists

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;


void print_list(node_t * head);
void push(node_t * head, int val);
void unshift(node_t ** head, int val);

int main() {
	// create the head node
	node_t * head = NULL;
	head = (node_t *) malloc(sizeof(node_t));

	if (head == NULL) {
		return -1;
	}

	head->val = 1;
	head->next = NULL;

	// add a second node
	head->next = (node_t *) malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;

	// printf("%d\n", head->val);
	// printf("%d\n", head->next->val);

	push(head, 3);
	push(head, 4);
	push(head, 5);

	unshift(&head, 0);
	unshift(&head, -1);

	print_list(head);

	return 0;
}

void print_list(node_t * head) {
	node_t * current = head;
	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

// add element to end of list
void push(node_t * head, int val) {
	// start from first node_t
	node_t * current = head;
	// loop to end of list
	while (current->next != NULL) {
		current = current->next;
	}
	// create node and add to end of list
	current->next = (node_t *) malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

// add element to beginning of list
void unshift(node_t ** head, int val) {
	node_t * new_node;
	new_node = (node_t *) malloc(sizeof(node_t));
	new_node->val = val;
	new_node->next = * head;

	* head = new_node;
}
