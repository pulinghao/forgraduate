#include <stdio.h>
#include "apue.h"

int glob = 6;
char buf[] = "a write to stdout.\n";

int main(void)
{
	int var;
	pid_t pid;

	var = 88;
	if (write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
	{
		/* code */
		err_sys("write error");
	}

	printf("before fork\n");

	if ((pid = fork())<0)
	{
		/* code */
		err_sys("fork error");
	} else if (pid == 0)
	{
		/* code */
		glob++;
		var++;
	} else {
		sleep(2);
	}

	printf("pid = %d, glob = %d, var=%d\n", getpid(),glob,var);

	// printf("hello, world!\n");
}