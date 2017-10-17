/**@file   strtoul.c
 * @brief  strtoul函数的使用方法
 * @author dtston-downey
 * @date   2017/10/14
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>


/**@brief  strtoul函数
 *@note 函数原型为unsigned long int strtoul(const char *nptr, char **endptr, int base);
 *@param   nptr 第一个参数为需要转换的字符串,函数实现中自动忽略字符串前的空格
 *@param   endptr 第二个参数为第一个不能转换的字符指针,这个参数事实上是使用者传进去的指针,当字符串中有不能被转换的值时,这个指针的值就是第一个不能被转换字符的地址.
 *即使是遇到不能转换的字符,函数返回值也是已经转换的字符值.如果没有转换任何数字,返回0
 *@param   base  第三个参数为转换的进制,如10为转换成十进制,如果字符串以0x开头,自动转换成16进制,如果以字符串0开头,默认转换成8进制,填0默认为10进制.
 */
unsigned long int strtoul(const char *nptr, char **endptr, int base);

/**@brief  strtoul的测试函数
 *
 */
int main(int argc,char*argv[])
{
	char arg_head[3]={0};
	char *ptr=NULL;
	int conver_num=0;
	if(argc<2)
	{
		printf("usage <file> <num> \r\n");
		return -1;
	}
	memcpy(arg_head,argv[1],2);
	if(0==strcmp(arg_head,"0x") || 0==strcmp(arg_head,"0X"))
	{
		conver_num=strtoul(argv[1],&ptr,16);
		printf("arg =%d\r\n",conver_num);
		if(NULL!=ptr)
		{
			printf("wrong byte =%c\r\n",*ptr);
		}
	}
	else
	{
		conver_num=strtoul(argv[1],&ptr,10);
		printf("arg =%d\r\n",conver_num);
		if(NULL!=ptr)
		{
			printf("wrong byte =%c\r\n",*ptr);
		}
	}
	return 1;
}
