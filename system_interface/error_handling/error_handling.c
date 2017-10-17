/**@file   error_handling.c
 * @brief  Linux下的错误处理
 * @author dtston-downey
 * @date   2017/10/17
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/**@brief  strerror
 *@param   __errnum  当程序执行错误时，比如打开不存在的文件，除数为0的情况，全局变量errno会被赋值，但是读取这个全局变量并不会让这个全局变量初始化，必须手动初始化。
 *@return
 */
char *strerror (int __errnum);

int main(int argc,char *argv[])
{
	errno = 0;
	int fd =open("aaa",O_RDONLY);
	printf("error = %s\r\n",strerror(errno));
	int a=8/1;
	printf("error = %s\r\n",strerror(errno));
	int a=8/0;
	printf("error = %s\r\n",strerror(errno));
}
