#include<stdio.h>
int main()
{
	float score;
	scanf("%f",&score);
	if(score>100||score<0)
		printf("error\n");
	else
	//if
	{
		if(score>=90)
			printf("A\n");
		else
			if(score>=80)
				printf("B\n");
			else
				if(score>=70)
					printf("C\n");
				else
					if(score>=60)
						printf("D\n");
					else
						printf("E\n");
	}
	//switch
/*	{
		switch((int)(score/10))
		{
		case 10:
		case 9:printf("A\n");break;
		case 8:printf("B\n");break;
		case 7:printf("C\n");break;
		case 6:printf("D\n");break;
		default:printf("E\n");break;
		}
	}*/
	return 0;
}