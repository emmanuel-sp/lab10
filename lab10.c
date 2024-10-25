#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char * argv[]) {
	int parent = getpid();
	printf("The parent's PID is %d\n", parent);
	printf("The parent is now forking.\n");
	int i = fork();
	if (i == 0) {
		printf("The child's PID is %d\n", getpid());
		printf("The child is executing ps.\n");
		char * exec[2] = {"ps", NULL};
		execve("/usr/bin/ps", exec, NULL);
	} else {
		wait(&i);
		printf("The parent waited patiently for its child to complete.\n");
		printf("The parent is executing ./countdown.out %s.\n", argv[1]);
		char * exec[3] = {"./countdown.out", argv[1], NULL};
		execve("countdown.out", exec, NULL);
	}

	return 0;

}
