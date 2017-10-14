#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
	pid_t pid;
	int status=0;
	printf("fork demo\r\n");
	pid =fork();
	if(0==pid)
	{
		printf("this is child process,pid=%d\r\n",getpid());
		printf("child's father's pid =%d\r\n",getppid());
		sleep(2);
	}
	else
	{	
		printf("this is father process,child pid =%d\r\n",pid);
		printf("father 's pid =%d\r\n",getpid());
		//wait(&status);
		waitpid(pid,&status,0);
		printf("child process %d exit with %d\r\n",pid,status);
	}
}
