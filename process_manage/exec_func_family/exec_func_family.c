/**@file   exec_func_family.c
 * @brief  exec函数族的使用
 * @author dtston-downey
 * @date   2017/10/17
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
int main(int argc,char *argv[])
{
		pid_t pid;
		int status=0;
		printf("fork demo\r\n");
		pid =fork();
		if(0==pid)
		{
			printf("this is child process,pid=%d\r\n",getpid());
		//	execlp("/home/downey/test_file","test_file",NULL);
			execl("/home/downey/test_file","test_file",NULL);
			printf("111");
			printf("%s\r\n",strerror(errno));
		}
		else
		{
			printf("this is father process,child pid =%d\r\n",pid);
			//wait(&status);
			waitpid(pid,&status,0);
			printf("child process %d exit with %d\r\n",pid,status);
		}

	return 1;
}
