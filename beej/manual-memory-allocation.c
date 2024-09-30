// https://beej.us/guide/bgc/html/split/manual-memory-allocation.html#manual-memory-allocation

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// 12.1 allocating & deallocating

	int *p = malloc(sizeof(int));
	
	*p = 12;
	
	printf("%d\n", *p);

	free(p);

	// 12.2 error checking
	int *x;
	
	//x = malloc(sizeof(int) * 10);

	if ((x = malloc(sizeof(int) * 10)) == NULL)
		printf("Error allocating 10 ints\n");

	// 12.3 allocating space for an array
  // char *p = malloc(3490); // space for a 3490-char len string



	return 0;
}
