/**@file   memset.c
 * @brief  memset函数的使用方法
 * @author dtston-downey
 * @date   2017/10/14
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <string.h>

/** @brief memset函数的使用方式
 *	@note  memset函数是按照字节的方式来进行初始化的，以下的输出结果时0x11111111,0x11111111，0x11111111，0x11111111，而不是1,1,1,1
 */
int main(void)
{
	int i=0;
	int a[3];
	memset(a,1,sizeof(a));
	for(;i<3;i++)
	{
		printf("%d.",a[i]);

	}
	printf("\r\n");
}
