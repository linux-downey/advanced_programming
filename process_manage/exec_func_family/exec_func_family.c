/**@file   exec_func_family.c
 * @brief  exec函数族的使用
 * @author dtston-downey
 * @date   2017/10/17
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	execlp("/bin/ls",NULL);
	return 1;
}
