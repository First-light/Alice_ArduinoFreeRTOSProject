#include "System.h"

int32_t INT_CHAR_Change(char* ar)
{
	int32_t i = 0;
	int32_t back = 0;
	int32_t m = 0;
	
	while(ar[i] != '\0')
	{
		i++;
	}
	for(;i>0;i--)
	{
		int32_t num = 1;
		int32_t j = 0;
		for(j=i;j>1;j--)
		{
			num *= 10;
		}
		back += num*(ar[m] - '0');
		
		m++;
	}
	return back;
}

void CHAR_INT_Change(char* ar2,int32_t b)
{//int转char*类型函数

	int32_t i;
	int32_t j;
	char ar[64] = {0};
	for(i=0;i <64;i++)
	{//将int按位转换为char型
		ar[i] = '0' + (b % 10);
		b /= 10;
		if(b == 0)
		{//如果int读完，结束循环
			break;
		}
	}
	strcpy(ar2,"\0");
	for(j = 0;i >= 0;i--,j++){
		ar2[i] = ar[j];//将数组倒置
	} 
}
