// https://www.tutorialspoint.com/cprogramming/c_pointer_to_pointer.htm

#include <stdio.h>

int main() {
	int a = 100;

	// pointer to int
	int * ptr = &a;

	// pointer to pointer (double pointer)
	int ** dblptr = &ptr;

	printf("Value of 'a' is : %d\n", a);
	printf("Value of 'a' using pointer (*ptr) is : %d\n", *ptr);
	printf("Value of 'a' using double pointer is : %d\n", **dblptr);
	printf("Address of 'a' (ptr) is : %p\n", ptr);
	printf("Address stored in double pointer is the same as ptr : %p\n", *dblptr);
	printf("Address of double pointer is : %p\n", dblptr);

	return 0;
}
