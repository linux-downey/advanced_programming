/**@file   strstr.c
 * @brief  在一个字符串中找另一个字符串，返回找到的字符串首地址
 * @author dtston-downey
 * @date   2017/10/20
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <string.h>

/** @brief	strstr函数的简单使用
 * @param   haystack 需要被查找的源字符串
 * @param   needle  需要查找的字符串
 * @return  char * 的指针，返回寻找字符串的首地址，如果源字符串不包含需要查询的字符串，返回NULL
 */
char *strstr(const char *haystack, const char *needle);


int main(void)
{
	char *test_str1="hello world !!\r\n";
	char *test_str2="or";
	char *test_str3="hh";
	char *ptr=NULL;

	ptr=strstr(test_str1,test_str2);
	printf("get str =%s \r\n",ptr);

	ptr=strstr(test_str1,test_str3);
	printf("get str =%s \r\n",ptr);

}
