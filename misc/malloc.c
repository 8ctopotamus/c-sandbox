// dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>

int main() {

	char *name;

	name = malloc(32);

	printf("What is your name?");
	scanf("%s", name);

	printf("Hello %s\n", name);

	free(name);
	name = NULL;

	return 0;
}
