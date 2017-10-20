/**@file   random_num.c
 * @brief  自己实现的random函数,获取一个随机数字
 * @author dtston-downey
 * @date   2017/10/20
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


/**@brief  localtime函数
 *@param   digit 需要获取随机数的位数,范围1-4
 *@return  返回随机数
*/
int get_random_num(int digit)
{
	if(digit>4||0>digit)
	{
		printf("digit should less than 4 and greater than 1");
	}
	int num;
	struct timespec time_struct_with_ns;
	clock_gettime(CLOCK_REALTIME,&time_struct_with_ns);
	printf("ns=%ld\r\n",time_struct_with_ns.tv_nsec);
	switch(digit)
	{
		case 1:return time_struct_with_ns.tv_nsec%10;
			break;
		case 2:return time_struct_with_ns.tv_nsec%100;
			break;
		case 3:return time_struct_with_ns.tv_nsec%1000;
			break;
		case 4:return time_struct_with_ns.tv_nsec%10000;
			break;
	}
	return 0;
//	printf("time =%d ns=%ld  \r\n",time_struct_with_ns.tv_sec,time_struct_with_ns.tv_nsec);

}


int main(int argc,char *argv[])
{
	int num;
	if(argc!=2)
	{
		printf("usage ./a.out <param>");
		exit(-1);
	}

	num=get_random_num(strtoul(argv[1],NULL,10));
	printf("%d\r\n",num);
}
