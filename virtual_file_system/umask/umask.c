#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>


//http://blog.csdn.net/luowanqian/article/details/16840575   st_mod成员参照这个博客


int main(void)
{
	struct stat test_file_stat;
	int fd;
	int ret_val;
	unsigned int smod;
	fd=open("/home/downey/test_file_umask",O_RDWR | O_CREAT,0755);
	if(fd<0)
	{
		printf("errno =%s \r\n",strerror(errno));
		exit(0);
	}
	ret_val=fstat(fd, &test_file_stat);
	if(ret_val<0)
	{
		printf("errno =%s \r\n",strerror(errno));
		exit(0);
	}
	smod=test_file_stat.st_mode&0x00000fff;
	printf("%d\r\n",smod);
	close(fd);
	exit(0);
}
