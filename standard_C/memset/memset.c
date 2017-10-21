#include <stdio.h>
#include <string.h>


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
