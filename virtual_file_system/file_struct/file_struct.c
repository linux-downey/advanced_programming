/**@file   file_struct.c
 * @brief  关于文件信息的结构体，以及一些权限相关的函数
 * @author dtston-downey
 * @date   2017/10/20
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**@brief  获取文件信息的结构体，如类型/组/用户id，权限信息等等
 * @param  path  文件路径，全路径
 * @param  buf  获取到的文件信息结构体
 */
int stat(const char *restrict path, struct stat *restrict buf);


int main(void)
{
	struct stat stat_buf;
	stat("/home/downey/test_file",&stat_buf);
	printf("stat_buf=%d\r\n",stat_buf.st_mode);
	printf("st_dev=%d\r\n",stat_buf.st_dev);
	printf("st_uid=%d\r\n",stat_buf.st_uid);
	printf("st_gid=%d\r\n",stat_buf.st_gid);
	printf("st_size=%d\r\n",stat_buf.st_size);

	printf("last modifi time=%d\r\n",stat_buf.st_mtim.tv_sec);

	printf("st_mode=%d\r\n",stat_buf.st_mode);

	return 0;
}
