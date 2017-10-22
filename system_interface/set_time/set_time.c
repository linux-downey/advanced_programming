/**@file   set_time.c
 * @brief  设置系统时间
 * @author dtston-downey
 * @date   2017/10/22
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>


/**@brief  将一个可读时间结构体struct tm（里面成员包含年月日时分秒等）转换成int型时间戳。
 * @param  __tp  时间
 * @return  int型时间戳
 */
time_t mktime (struct tm *__tp);

/**@brief  设置系统时间
 * @param  __tv  struct timeval型时间，里面有时间戳（秒）和微秒值成员
 * @param  __tz  struct timezone时区区分信息，中国北京时间的时区为东八区
 * @return  0-成功，-1-失败
 * @note  这个函数的执行必须得有root权限，普通用户的权限不能执行这个函数
 */
int settimeofday (const struct timeval *__tv,
			 const struct timezone *__tz)；

/**@brief  设置系统时间
 * @bote  先生成时间戳，然后再调用settimeofday设置时间
 *
 */
int main(void)
{
	int ret_val;

	time_t time_num;
	struct timezone time_zone;

	struct tm *time_struct;
	struct timeval  timeval;
	__timezone_ptr_t timezone;

	struct tm time_real;

	time_real.tm_hour=15;
	time_real.tm_mday=22;
	time_real.tm_min=33;
	time_real.tm_mon=9;
	time_real.tm_sec=0;
	time_real.tm_year=117;
	time_num=mktime(&time_real);
	printf("time num =%d\r\n",time_num);

//	while(1);
/*	gettimeofday(&timeval,timezone);
	time_struct=localtime(&timeval.tv_sec);
	printf("time::%d,%d,%d,%d,%d,%d,%d\r\n",time_struct->tm_year+1900,time_struct->tm_mon+1,time_struct->tm_mday,
				time_struct->tm_hour,time_struct->tm_min,time_struct->tm_sec,timeval.tv_sec);
*/
	timeval.tv_sec=time_num;
	time_zone.tz_minuteswest=0;

	ret_val=settimeofday(&timeval,&time_zone);
	if(ret_val!=0)
	{
		printf("error =%s \r\n",strerror(errno));
		return -1;
	}

	time_struct=localtime(&timeval.tv_sec);
	printf("time::%d,%d,%d,%d,%d,%d,%d\r\n",time_struct->tm_year+1900,time_struct->tm_mon+1,time_struct->tm_mday,
					time_struct->tm_hour,time_struct->tm_min,time_struct->tm_sec,timeval.tv_sec);
	return 1;
}
