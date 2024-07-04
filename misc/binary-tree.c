// https://learn-c.org/en/Binary_trees

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node * left;
	struct node * right;
} node_t;

void insert(node_t * tree, int val);
void print_tree(node_t * current);
void printDFS(node_t * current); // depth-first search

int main() {
	node_t * test_list = (node_t *) malloc(sizeof(node_t));
	
	// set values explicitly (alternative would be calloc())
	test_list->val = 0;
	test_list->left = NULL;
	test_list->right = NULL;

	insert(test_list, 5);
	insert(test_list, 8);
	insert(test_list, 4);
	insert(test_list, 3);

	printDFS(test_list);
	printf("\n");

	return 0;
}

void insert(node_t * tree, int val) {

}

void print_tree(node_t * current) {

}

void printDFS(node_t * current) {
	
} 
