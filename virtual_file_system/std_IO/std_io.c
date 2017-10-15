#include <stdio.h>
#include <unistd.h>
#include <string.h>


//存到一个文件里  未完成
int main(void)
{
	unsigned char buf[1024]={0};
	unsigned char storage_buf[1204]={0};

	int read_bytes;
	int count =2;
	char *test_str="hello  std file test\r\n";
	char *test_str_stdout="stderr test\r\n";

	write(1,test_str,strlen(test_str));
	write(STDOUT_FILENO,test_str_stdout,strlen(test_str_stdout));

	write(STDERR_FILENO,"std err test\r\n",14);


	while(count--)
	{
		read_bytes=read(STDIN_FILENO,buf,sizeof(buf));
		if(1==count)
		{
			memcpy(storage_buf,buf,read_bytes);
		}
		else
		{
			memcpy(&storage_buf+,buf,read_bytes);
		}

	}

	printf("read bytes =%d\r\n",read_bytes);
	printf("read buf=%s \r\n",buf);
}
