#include <stdio.h>

int addition(int a, int b) {
	return a + b;
}

int main() {
	int a, b, answer;

	a = 10;
	b = 11;

	answer = addition(a, b);

	printf("%d\n", answer);

	return 0;
}
