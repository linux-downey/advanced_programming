#include <sys/stat.h>
#include <stdio.h>
#include <string.h>


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

	return 0;
}
