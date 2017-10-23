/**@file   file_oprt.c
 * @brief  linux 下文件操作编程
 * @author dtston-downey
 * @date   2017/10/14
 * @version  1.0.0
 * 修订说明：最初版本
 */


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


/**@brief  文件编程中的open函数
 *@param   __file  第一个参数为文件路径，
 *@param   __oflag  第二个参数为打开标志，值得一提的是，当标志位设置了O_CREAT位时，当文件不存在时就会创建文件，这时需要填入第三个参数，文件操作权限，例如：0777
 *@note   O_APPEND 为追加写，O_RDWR  可读可写打开  O_RDONLY 只读打开  O_WRNOLY  只写打开
 */
int open (const char *__file, int __oflag, ...);
/**@brief  文件编程中的read函数
 *@param   __fd  文件句柄
 *@param   __buf  读入的buf
 *@param   __nbytes  需要读入的字节数
 *@return  读取到的字节数，可能和第三个参数不符，当文件没有足够的字节时，返回值为读到的字节，如果返回0，则表示读到了文件末尾。返回-1表示读错误
 */
ssize_t read (int __fd, void *__buf, size_t __nbytes);
/**@brief  文件编程中的write函数
 *@param   __fd  文件句柄
 *@param   __buf  需要写入的buf
 *@param   __n  需要写入的字节数
 *@return  成功写入的字节数，写入失败时返回-1
 */
ssize_t write (int __fd, const void *__buf, size_t __n);
/**@brief  文件编程中的lseek函数
 *@param   __fd  文件句柄
 *@param   __offset  相对于whence的偏移值
 *@param   __whence  基准值
 *@return  因为用户在读写文件的时候，文件指针会自动偏移，所以有时候需要定位到文件某处就可以用到这个函数
 */
__off_t lseek (int __fd, __off_t __offset, int __whence)；




int main(int argc,char *argv[])
{
	int fd=0;

	unsigned char read_buf[20]={0};
	unsigned char storage_buf[1024]={0};
	int ret_len;
	int file_index=0;
	char *write_buf="jlasjfljsdfljklajfkldjdkljsklfjkladsjfkljskfljklsdjfkljkdasfjljkadsfjkladfasdfhdkjasfhkjasfhkjhjkhjkhkjahsfkjdhjkdasfhjk \
			faksajkfljdflsjljaskfljadsfljkdasjfkldajsfkljasdfkljksdfjkljasfkljaskdfkldfjklijslakfjidasjflasjdflekjdlkjafiojadklfjkldafjjklajdf";

	fd = open ("/home/downey/file_oprt_test_file",O_RDWR|O_CREAT,0777);
	if(fd<0)
	{
		printf("open file failed\r\n");
		return -1;
	}

	if((ret_len=write(fd,write_buf,strlen(write_buf)))!=strlen(write_buf))
	{
		printf("write failed !!\r\n");
		return -1;
	}

//	if(ret_len!=)
//	{
//		printf("write failed !!\r\n");
//	}
	printf("write len =%d \r\n",ret_len);

	lseek(fd,0,SEEK_SET);

	while((ret_len=read(fd,&storage_buf[file_index],10))!=0)
	{
		printf("ret_len =%d\n",ret_len);
		if(ret_len<0)
		{
			return -1;
			printf("read failed!!\r\n");
		}
		else
		{
			file_index+=ret_len;
		}
	}
	printf("read data from file =%s\r\n",storage_buf);


	close(fd);
}
