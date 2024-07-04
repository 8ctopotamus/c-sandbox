#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_book {
	char title[64];
	int pages;
	struct s_book *next;
};

typedef struct s_book Book; 

Book *first;
int numBooks;

void addBook(char *title, int pages) {
	Book *p, *new;

	if (!first) {
		p = malloc(sizeof(Book));
		memset(p, 0, sizeof(Book));
		numBooks++;
		strncpy(p->title, title, 63);
		p->pages = pages;
		p->next = 0;
		first = p;

		return;
	} 

	for (p = first; p->next; p++);

	new = malloc(sizeof(sizeof(Book)));
	memset(new, 0, sizeof(Book));
	numBooks++;
	strncpy(new->title, title, 63);
	new->pages = pages;
	new->next = 0;
	
	p->next = new;

	return;
}

void listbooks(char *searchstr) {
	Book *p;

	for (p = first; p->next; p++) {
		if (!searchstr || !strcmp(searchstr, p->title)) {
			printf("Pages %d\tTitle: '%s'\n", p->pages, p->title);
		}
	}
	
	return;
}

int main() {
	first = 0;
	numBooks = 0;

	addBook("The Hobbit", 1500);
	printf("%s\n", first->title);

	addBook("Lord of the Flies", 1000);
	printf("%s\n", first->next->title);

	listbooks(0);
	

	return 0;
}
