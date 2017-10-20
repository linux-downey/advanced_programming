/**@file   time_api.c
 * @brief  linux 下时间值的获取
 * @author dtston-downey
 * @date   2017/10/20
 * @version  1.0.0
 * 修订说明：最初版本
 */
#include <stdio.h>
#include <string.h>
#include <time.h>


/**@brief  获取时间戳
 * @param __timer 时间戳的值,原型为long int型
 * @return time_t类型的时间戳,原型为long int型
 */
time_t time (time_t *__timer);

/**@brief  localtime函数
 *@param   __timer 当前的时间戳
 *@return  返回当前的时间结构体数据,struct tm类型的数据,结构体内包含年月日时分秒周的数据,值得注意的是,
 *@return  年是tm_year成员,需要加上1900为当前时间,月需要加上1才是准确月份
*/
struct tm *localtime (const time_t *__timer);


/**@brief  获取时间戳,获取的结果中有两个参数,一个为时间戳秒,一个为ns,时间精确到ns
 * @param  __clock_id 需要获取的时间选项
 * @param  __tp  获取的时间结构体
 * @return 0为成功,-1为失败
 * @note  __clock_id一共有四个选项,CLOCK_REALTIME为获取当前的时间,CLOCK_PROCESS_CPUTIME_ID为进程当前执行时间,
 * @note  CLOCK_THREAD_CPUTIME_ID为线程当前执行时间
 */
int clock_gettime (clockid_t __clock_id, struct timespec *__tp);

int main(void)
{
	struct tm *time_struct;
	time_t real_time;
	struct timespec time_struct_with_ns;

	real_time=time(NULL);

	time_struct=localtime(&real_time);

	clock_gettime(CLOCK_REALTIME,&time_struct_with_ns);
	printf("time =%d ns=%ld  \r\n",time_struct_with_ns.tv_sec,time_struct_with_ns.tv_nsec);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time_struct_with_ns);
	printf("time =%d ns=%ld  \r\n",time_struct_with_ns.tv_sec,time_struct_with_ns.tv_nsec);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time_struct_with_ns);
	printf("time =%d ns=%ld  \r\n",time_struct_with_ns.tv_sec,time_struct_with_ns.tv_nsec);

	clock_gettime(CLOCK_THREAD_CPUTIME_ID,&time_struct_with_ns);
	printf("time =%d ns=%ld  \r\n",time_struct_with_ns.tv_sec,time_struct_with_ns.tv_nsec);

	printf("time::%d,%d,%d,%d,%d,%d,%d\r\n",time_struct->tm_year+1900,time_struct->tm_mon+1,time_struct->tm_mday,
			time_struct->tm_hour,time_struct->tm_min,time_struct->tm_sec);

	printf("time = %d \r\n",real_time);

	return 1;
}

