/**@file   umask.c
 * @brief  umask--创建新建文件屏蔽位
 * @author dtston-downey
 * @date   2017/10/23
 * @version  1.0.0
 * 修订说明：最初版本
 */

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/types.h>


//http://blog.csdn.net/luowanqian/article/details/16840575   st_mod成员参照这个博客


/**@brief  获取系统屏蔽位设置值
 * @return 系统屏蔽位
 * @note   umask函数参数为需要设置的umask值,返回之前设置的umask值,所以可以通过设置屏蔽位来获取屏蔽位,然后设置回之前状态实现获取屏蔽位
 */
mode_t getumask(void)
{
	mode_t mask=umask(0);
	umask(mask);
	return mask;
}

/**@brief  设置系统文件屏蔽位
 * @param  需要设置的屏蔽位
 * @return 之前的系统屏蔽位
 * @note   系统屏蔽位指在创建文件或者目录且并未指定相应的权限位时,默认的文件或目录权限,一般情况下为2,即屏蔽其他用户的写权限
 */
__mode_t umask (__mode_t __mask);

int main(void)
{
	struct stat test_file_stat;
	int fd;
	int ret_val;
	unsigned int smod;
	mode_t umask_mod;
	fd=open("/home/downey/test_file_umask",O_RDWR | O_CREAT,0755);
	//fd=creat();
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
	smod=test_file_stat.st_mode&0177777;
	printf("%o\r\n",smod);
	umask_mod=getumask();
	printf("umask =%o \r\n",umask_mod);
	close(fd);
	exit(0);
}
