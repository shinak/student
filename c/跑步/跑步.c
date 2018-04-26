#include <stdio.h>

void main()
{
	int person = 80;
	int norun = 0;
	float yuan = 160.00;
	float agv = 0;
	for(; norun <= 80; norun ++)
	{
		agv = yuan / (person - norun);
		if(norun == 80)
		{
			printf("person = %d 人\tnorun = %d 人\trun = %d 人\tagv = 0 元 \n",person,norun,(person - norun));break;
		}
		printf("person = %d 人\tnorun = %d 人\trun = %d 人\tagv = %0.2f 元 \n",person,norun,(person - norun),agv);
	}
}