/**@file   net_param_conver.c
 * @brief  网络编程中的一些转换函数的使用方法
 * @author dtston-downey
 * @date   2017/10/14
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <arpa/inet.h>

/**@brief  将点分十进制的IP转换成网络字节序的32位IP地址
 * @param cp 点分十进制的IP地址
 * @return in_addr_t类型的数据,原型是unsigned int类型的数据
 */
in_addr_t inet_addr(const char *cp);

/**@brief  将网络字节序的32位IP地址转换成点分十进制的IP
 * @param in 网络字节序IP地址
 * @return 点分十进制的IP
 */
char *inet_ntoa(struct in_addr in);

/**@brief  将网络编程中的端口号转换成网络字节序的端口号
 * @param hostshort 端口号
 * @return 网络字节序的端口号
 */
uint16_t htons(uint16_t hostshort);



#define  TEST_IP     "192.168.1.1"
#define  TEST_PORT   1234

int main(void)
{
	char *ip_str=NULL;
	short port=TEST_PORT;
	unsigned int ip=inet_addr(TEST_IP);
	printf("IP 32 =%d\r\n",ip);

//	ip_str=inet_ntoa((struct in_addr)ip);
//	printf("IP string =%s\r\n",ip_str);

	printf("port before conver MSB =%x\r\n",(unsigned char)port>>8);
	printf("port before conver LSB =%x\r\n",(unsigned char)port);

	port=htons(TEST_PORT);
	printf("port MSB =%x\r\n",(unsigned char)port>>8);
	printf("port LSB =%x\r\n",(unsigned char)port);
}
