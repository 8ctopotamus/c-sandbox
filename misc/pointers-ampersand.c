#include <stdio.h>

void addition(int a, int b, int *target) {
	*target = a + b;

	return;
}

int main() {
	int a, b, answer;

	a = 10;
	b = 11;

	addition(a, b, &answer);

	printf("%d\n", answer);

	return 0;
}
