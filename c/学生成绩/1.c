#include<stdio.h>
#include<string.h>
void menu()
{
	printf("________________________________________________________________________________\n");
	printf("                               学生成绩管理系统\n");
	printf("________________________________________________________________________________\n");
	printf("|%-10s|%-12s|%-10s|%-10s|%-10s|%-10s|%-10s|\n","姓名","学号","数学","物理","英语","总分","平均分");
	printf("菜单:\n");
	printf("1、录入每个学生的学号和各科考试成绩;\n");
	printf("2、计算每门课程的总分和平均分\n");
	printf("3、计算每个学生的总分和平均分\n");
	printf("4、按每个学生的总分由高到低排出名次表\n");
	printf("5、按每个学生的总分由低到高排出名次表\n");
	printf("6、按学号由小到大排出成绩表\n");
	printf("7、按学号查询学生排名及各科考试成绩\n");
	printf("8、按优秀、良好、中等、及格、不及格5个类别，对每门课程分别统计每个类别的人数和百分比\n");
	printf("9、输出每个学生的学号、各科成绩、总分、平均分\n");
	printf("10、输出每门课程的总分和平均分\n");
	printf("0、退出系统\n");
}
void frist()
{
	printf("________________________________________________________________________________\n");
	printf("                               学生成绩管理系统\n");
	printf("________________________________________________________________________________\n");
	printf("|%-10s|%-12s|%-10s|%-10s|%-10s|%-10s|%-10s|","姓名","学号","数学","物理","英语","总分","平均分");
}
int main()
{
	int j,k;
	float t;
	char str1[10];
	int str2[10];
	float c[30],d[30],e[30],sum4[30],av4[30];
	char a[30][10];
	int n,f,i,b[30];
	float sum1=0.0,sum2=0.0,sum3=0.0;
	float av1,av2,av3;
	menu();
	while(1)
	{
		printf("操作:");
		scanf("%d",&n);
		if(n==0)
			break;
		if(n<0||n>10)
			printf("错误!请重新:");
		else switch(n)
		{
			case 1:
				{
					while(1)
					{
						printf("输入班级总人数:");
						scanf("%d",&f);
						if(f>30)
							printf("错误，请重新");
						else
							break;
					}
					for(i=0;i<f;i++)
						scanf("%s%d%f%f%f",&a[i],&b[i],&c[i],&d[i],&e[i]);
					printf("下一步");
				};break;
			case 2:
				{
					for(i=0;i<f;i++)
					{
						sum1+=c[i];
						sum2+=d[i];
						sum3+=e[i];
					}
					av1=sum1/f;
					av2=sum2/f;
					av3=sum3/f;
					printf("下一步");
				};break;
			case 3:
				{
					for(i=0;i<f;i++)
					{
						sum4[i]=c[i]+d[i]+e[i];
						av4[i]=sum4[i]/3;
					}
					printf("下一步");
				};break;
			case 4:
				{
					for(i=0;i<f;i++)
					{
						for(j=0;j<f;j++)
						{
							if(sum4[i]>sum4[j])
							{
								t=sum4[i];
								sum4[i]=sum4[j];
								sum4[j]=t;
								strcpy(str1,a[i]);
								strcpy(a[i],a[j]);
								strcpy(a[j],str1);
								k=b[i];
								b[i]=b[j];
								b[j]=k;
								t=c[i];
								c[i]=c[j];
								c[j]=t;
								t=d[i];
								d[i]=d[j];
								d[j]=t;
								t=e[i];
								e[i]=e[j];
								e[j]=t;	
								t=av4[i];
								av4[i]=av4[j];
								av4[j]=t;
							}	
							else
								continue;
						}
					}
					frist();
					for(i=0;i<f;i++)
							printf("|%-10s|%-12d|%-10.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
						printf("下一步");
				};break;
			case 5:
				{	
					for(i=0;i<f;i++)
					{
						for(j=0;j<f;j++)
						{
							if(sum4[i]<sum4[j])
							{
								t=sum4[i];
								sum4[i]=sum4[j];
								sum4[j]=t;
								strcpy(str1,a[i]);
								strcpy(a[i],a[j]);
								strcpy(a[j],str1);
								k=b[i];
								b[i]=b[j];
								b[j]=k;
								t=c[i];
								c[i]=c[j];
								c[j]=t;
								t=d[i];
								d[i]=d[j];
								d[j]=t;
								t=e[i];
								e[i]=e[j];
								e[j]=t;	
								t=av4[i];
								av4[i]=av4[j];
								av4[j]=t;
							}	
							else
								continue;
						}
					}
					frist();
					for(i=0;i<f;i++)
						printf("|%-10s|%-12d|%-10.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
					printf("下一步");
				};break;
			case 6:
				{
					for(i=0;i<f;i++)
					{
						for(j=0;j<f;j++)
						{
							if(b[i]<b[j])
							{	
								k=b[i];
								b[i]=b[j];
								b[j]=k;
								t=sum4[i];
								sum4[i]=sum4[j];
								sum4[j]=t;
								strcpy(str1,a[i]);
								strcpy(a[i],a[j]);
								strcpy(a[j],str1);
								t=c[i];
								c[i]=c[j];
								c[j]=t;
								t=d[i];
								d[i]=d[j];
								d[j]=t;
								t=e[i];
								e[i]=e[j];
								e[j]=t;	
								t=av4[i];
								av4[i]=av4[j];
								av4[j]=t;
							}	
							else
								continue;
						}
					}
					frist();
					for(i=0;i<f;i++)
						printf("|%-10s|%-12d|%-10.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
					printf("下一步");
				};break;
			case 7:
				{
					printf("需要查询的学号:");
					scanf("%d",&k);
					for(i=0;i<f;i++)
					{
						if(k==b[i])
							printf("|%-10s|%-12d|%-10.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
					}
					printf("下一步");
				   };break;
			case 8:;break;
			case 9:
				{
					frist();
					for(i=0;i<f;i++)
					     printf("|%-10s|%-12d|%-10.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
					printf("下一步");
				};break;
			case 10:
				{
					printf("|%-10s|%-12s|","总分"," ");
					printf("%-10.1f|%-10.1f|%-10.1f|\n",sum1,sum2,sum3);
					printf("|%-10s|%-12s|","平均分"," ");
					printf("%-10.1f|%-10.1f|%-10.1f|\n",av1,av2,av3);
					printf("下一步");
				};break;	
		}
	}
	return 0;
}
