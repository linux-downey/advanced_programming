/**@file   struct_stat_details.c
 * @brief  文件(目录)的结构体信息中权限位详解2465
 * @author dtston-downey
 * @date   2017/10/20
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
	struct stat stat_buf;
	stat("/home/downey/test_file",&stat_buf);

	printf("st_dev=%ld\r\n",stat_buf.st_dev);  //long long int型变量,设备类型

	printf("st_uid=%d\r\n",stat_buf.st_uid);   //u32类型变量,用户id
	printf("st_gid=%d\r\n",stat_buf.st_gid);   //u32类型变量,组id
	printf("st_size=%d\r\n",stat_buf.st_size); //文件大小  long int型

	printf("last modifi time=%d\r\n",stat_buf.st_mtim.tv_sec);   //u32类型变量,最后修改的时间

	printf("st_mode=%d\r\n",stat_buf.st_mode);  //文件的各种性质

	printf("st_blksize=%d\r\n",stat_buf.st_blksize);


	return 0;
}
