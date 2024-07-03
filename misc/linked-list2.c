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
int shift(node_t ** head);
int pop(node_t * head);
int remove_item_by_index(node_t ** head, int target_idx);

int main() {
	// create the head node
	node_t * head = NULL;
	head = (node_t *) malloc(sizeof(node_t));

	if (head == NULL) {
		return -1;
	}

	// add some starting values to list

	head->val = 1;
	head->next = NULL;

	// add a second node
	head->next = (node_t *) malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;

	// printf("%d\n", head->val);
	// printf("%d\n", head->next->val);

	// add to end
	push(head, 3);
	push(head, 4);
	push(head, 5);

	// add to beginning
	unshift(&head, 0);
	
	printf("List after using `unshift` and `push`:\n");
	print_list(head);

	int first_val = shift(&head);
	printf("First item: %d\n", first_val);

	int last_val = pop(head);
	printf("Last item: %d\n", last_val);
	
	printf("List after using `shift` and `pop`:\n");
	print_list(head);

	int specific_val_by_idx = remove_item_by_index(&head, 2);	
	printf("Val from index 2: %d\n", specific_val_by_idx);

	printf("List after using `remove_item_by_index`\n");
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

// add element to beginning of list
void unshift(node_t ** head, int val) {
	node_t * new_node;
	new_node = (node_t *) malloc(sizeof(node_t));
	new_node->val = val;
	new_node->next = * head;

	* head = new_node;
}

// get val from beginning of list and remove first node
int shift(node_t ** head) {
	int retval = -1;
	node_t * next_node = NULL;

	if (*head == NULL) {
		return -1;
	}
	
	next_node = (*head)->next;
	retval = (*head)->val;
	
	free(*head);
	*head = next_node;

	return retval;
};

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

// get val from last node in list and remove from list
int pop(node_t * head) {
	int retval = 0;

	// if only one item in the list, remove it
	if (head->next == NULL) {
		retval = head->val;
		free(head);
		return retval;
	}

	// iterate to the second-to-last item in list
	node_t * current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	
	// now current points to the second last item of the list, so let's remove current->next
	retval = current->next->val;
	free(current->next);
	current->next = NULL;

	return retval;
}

int remove_item_by_index(node_t ** head, int target_idx) {
	int retval = -1;
	
	node_t * current = * head;
	node_t * temp_node = NULL;
	
	if (target_idx == 0) {
		return shift(head);
	}

	int i = 0;
	for (i = 0; i < target_idx - 1; i++) {
		if (current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	if (current->next == NULL) {
		return -1;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}
