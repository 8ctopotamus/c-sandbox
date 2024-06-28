#include <stdio.h>
#include <unistd.h>

/*
 After compiling and running ./fork, 
 you can follow the tail (last appended entry) of the file in another terminal with command: 
 
 `tail -f text.txt` 
 */


int main() {
	int x;
	FILE *fd;

	x = fork(); // returns a new process ID (PID)
	while(1) {
		fd = fopen("text.txt", "a");
		fprintf(fd, "%d\n", x);
		fclose(fd);
		sleep(1);
	}
	return 0;
}
