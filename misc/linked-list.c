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

	for (p = first; p->next; p = p->next);

	new = malloc(sizeof(Book));
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

	for (p = first; p; p = p->next) {
		if (!searchstr || !strcmp(searchstr, p->title)) {
			printf("Pages %d\tTitle: '%s'\n", p->pages, p->title);
		}
	}
	
	return;
}

int removebook(char *searchstr) {
	Book *p, *penultimate;

	for (p = first; penultimate = p; p = p->next) {
		if (!searchstr || !strcmp(searchstr, p->title)) {
			if (first == p) {
				first = p->next;
			} else {
				penultimate->next = (p->next) ? p->next : 0;
			}
			free(p);
			return 1;
		}
	}
	
	return 0;
}

int main() {
	first = 0;
	numBooks = 0;

	addBook("The Hobbit", 1500);
	//printf("%s\n", first->title);
	addBook("Lord of the Flies", 1000);
	//printf("%s\n", first->next->title);
	addBook("The Two Towers", 2000);
	addBook("Return of the King", 1750);

	// printf("%s\n", first->next->next->title);

	int removedbook = removebook("Lord of the Flies");
	printf("Book removed: %d\n", removedbook);

	listbooks(0); // list all
	
	//listbooks("The Two Towers"); // list a specific book

	return 0;
}
