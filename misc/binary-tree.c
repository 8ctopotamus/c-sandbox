// https://learn-c.org/en/Binary_trees

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node * left;
	struct node * right;
} node_t;

void insert(node_t * tree, int val);
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
	if (tree->val == 0) {
		// insert on empty first position node
		tree->val = val;
	} else {
		// insert on left if incoming val is < current node's val
		if (val < tree->val) {
			// if left isn't empty
			if (tree->left != NULL) {
				insert(tree->left, val);
			} else {
				// if is empty, allocate memory for a new node
				tree->left = (node_t *) malloc(sizeof(node_t));
				// set values explicitly (alternative would be calloc())
				tree->left->val = val;
				tree->left->left = NULL;
				tree->left->right = NULL;
			}
		}
		// insert on right if incoming val is >= current node's val
		else if (val >= tree->val) {
			if (tree->right != NULL) {
				insert(tree->right, val);
			}	else {
				tree->right = (node_t *) malloc(sizeof(node_t));
				tree->right->val = val;
				tree->right->left = NULL;
				tree->right->right = NULL;
			}
		}
	}
}

void printDFS(node_t * current) {
	if (current == NULL) return;
	if (current != NULL) printf("%d ", current->val);
	if (current->left != NULL) printDFS(current->left);
	if (current->right != NULL) printDFS(current->right);
} 
