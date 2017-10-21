/**@file   stdio.c
 * @brief  标准输入和标准输出的
 * @author dtston-downey
 * @date   2017/10/21
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>




/**@brief  关于标准输入输出的测试函数
 * @note  在shell启动的时候,系统会自动打开三个文件:标准输入,标准输出,标准错误.fd分别为0,1,2.
 * @note  默认情况下,往标准错误和标准输出文件写数据,会输出要屏幕
 * @note  当从标准输入读入数据时,数据buf会得到用户输入的数据,buf中的数据结尾并不是\0,而是\a,需要注意
 *
 */
int main(void)
{
	unsigned char buf[1024]={0};
	int i=0;
//	unsigned char storage_buf[1204]={0};

	int read_bytes;
	char *test_str="hello  std file test\r\n";
	char *test_str_stdout="stderr test\r\n";

	write(1,test_str,strlen(test_str));
	write(STDOUT_FILENO,test_str_stdout,strlen(test_str_stdout));

	write(STDERR_FILENO,"std err test\r\n",14);

	memset(buf,1,sizeof(buf));
	read_bytes=read(STDIN_FILENO,buf,sizeof(buf));


	printf("read bytes =%d\r\n",read_bytes);
	printf("read buf=%s \r\n",buf);
	for(i=0;i<20;i++)
	{
		printf("%d  ",buf[i]);
	}
	printf("\r\n");
}
