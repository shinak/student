#include <stdio.h>
#include <string.h>
#include <windows.h>
void menu()
{
	printf("┌──────────────────────────────────┐\n");
	printf("│                          学生成绩管理系统                          │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│                               菜单                                 │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│                ① 录入每个学生的学号和各科考试成绩                 │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│                О 退出系统                                         │\n");
	printf("└──────────────────────────────────┘\n");
	
}
void format1()
{
	printf("┌──────────────────────────────────┐\n");
}
void format2()
{
	printf("├──────────────────────────────────┤\n");
}
void format3()
{
	printf("└──────────────────────────────────┘\n");
}
void name()
{
	printf("├───┬────┬───┬───┬───┬────┬────┬───┤\n");
	printf("│%-6s│%-8s│%-6s│%-6s│%-6s│%-8s│%-8s│%-6s│\n","姓名","学号","数学","物理","英语","总分","平均分","排名");
	printf("├───┴────┴───┴───┴───┴────┴────┴───┤\n");
	printf("2、计算每门课程的总分和平均分\n");
	printf("3、计算每个学生的总分和平均分\n");
	printf("4、按每个学生的总分由高到低排出名次表\n");
	printf("5、按每个学生的总分由低到高排出名次表\n");
	printf("6、按学号由小到大排出成绩表\n");
	printf("7、按学号查询学生排名及各科考试成绩\n");
	printf("8、按优秀、良好、中等、及格、不及格5个\n类别，对每门课程分别统计每个类别的人数和百分比\n");
	printf("9、输出每个学生的学号、各科成绩、总分、平均分\n");
	printf("10、输出每门课程的总分和平均分\n");
	printf("0、退出系统\n");
}
void main()
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
		printf("%25s","操作:");
		scanf("%d",&n);
		if(n<0||n>1)
			printf("%30s","错误!请重新输入\n");
		else
			break;
	}
	while(1)
	{
		if(n==0)
			break;
		switch(n)                    //frist
		{
		case 1:                          //1
			{
				system("cls");
				while(1)
				{
					format1();
					printf("│                ① 录入每个学生的学号和各科考试成绩                 │\n");
					format3();
					printf("┌───┬────┬───┬───┬───┐\n");
					printf("│%-6s│%-8s│%-6s│%-6s│%-6s│\n","姓名","学号","数学","物理","英语");
					printf("└───┴────┴───┴───┴───┘\n");
					printf("%35s","输入班级总人数:");
					scanf("%d",&f);
					if(f>30)
					{
						system("cls");
						printf("%35s","错误，请重新输入\n");
					}
					else
						break;
				}
				for(i=0;i<f;i++)
					scanf("%s%d%f%f%f",&a[i],&b[i],&c[i],&d[i],&e[i]);
				system("cls");
				printf("┌────────────────────┐\n");
				printf("│            学生成绩表                  │\n");
				printf("├───┬────┬───┬───┬───┤\n");
				printf("│%-6s│%-8s│%-6s│%-6s│%-6s│\n","姓名","学号","数学","物理","英语");
				for(i=0;i<f;i++)
				{
					printf("├───┼────┼───┼───┼───┤\n");
					printf("│%-6s│%-8d│%-6.1f│%-6.1f│%-6.1f│\n",a[i],b[i],c[i],d[i],e[i]);
				}
				printf("└───┴────┴───┴───┴───┘\n");
				printf("┌──────────────────────────────────┐\n");
				printf("│                               菜单                                 │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ① 计算每门课程的总分和平均分                    │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ② 计算每个学生的总分和平均分                    │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ③ 成绩排序                                      │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   О  返回首页                                     │\n");
				printf("└──────────────────────────────────┘\n");
				while(1)
				{
					printf("%25s","操作:");
					scanf("%d",&n);
					break;
				}
				switch(n)                 //two
				{
				case 1:
					{
						system("cls");
						for(i=0;i<f;i++)
						{
							sum1+=c[i];
							sum2+=d[i];
							sum3+=e[i];
						}
						av1=sum1/f;
						av2=sum2/f;
						av3=sum3/f;
						printf("┌────────────────────┐\n");
						printf("│            学生成绩表                  │\n");
						printf("├───┬────┬───┬───┬───┤\n");
						printf("│%-6s│%-8s│%-6s│%-6s│%-6s│\n","姓名","学号","数学","物理","英语");
						for(i=0;i<f;i++)
						{
							printf("├───┼────┼───┼───┼───┤\n");
							printf("│%-6s│%-8d│%-6.1f│%-6.1f│%-6.1f│\n",a[i],b[i],c[i],d[i],e[i]);
						}
						printf("├───┼────┼───┼───┼───┤\n");
						printf("│%-6s│%-8s│%-6.1f│%-6.1f│%-6.1f│\n","总分"," ",sum1,sum2,sum3);
						printf("├───┼────┼───┼───┼───┤\n");
						printf("│%-6s│%-8s│%-6.1f│%-6.1f│%-6.1f│\n","平均分"," ",av1,av2,av3);
						printf("└───┴────┴───┴───┴───┘\n");
						printf("┌──────────────────────────────────┐\n");
						printf("│                               菜单                                 │\n");
						printf("├──────────────────────────────────┤\n");
						printf("│                   ① 计算每个学生的总分和平均分                    │\n");
						printf("├──────────────────────────────────┤\n");
						printf("│                   О  返回首页                                     │\n");
						printf("└──────────────────────────────────┘\n");
						while(1)
						{
							printf("%25s","操作:");
							scanf("%d",&n);
							break;
						}
						switch(n)
						{
						case 1:n=2;break;
						default:n=4;break;
						}
					}break;
				case 2:n=2;break;
				case 3:n=3;break;
				default:n=4;break;
				}
			}break;
		case 2:                               //2
			{
				for(i=0;i<f;i++)
				{
					sum4[i]=c[i]+d[i]+e[i];
					av4[i]=sum4[i]/3;
				}
				system("cls");
				printf("┌──────────────────────────────┐\n");
				printf("│                          学生成绩管理系统                  │\n");
				printf("├───┬────┬───┬───┬───┬────┬────┤\n");
				printf("│%-6s│%-8s│%-6s│%-6s│%-6s│%-8s│%-8s│\n","姓名","学号","数学","物理","英语","总分","平均分");	
				for(i=0;i<f;i++)
				{
					printf("├───┼────┼───┼───┼───┼────┼────┤\n");
					printf("│%-6s│%-8d│%-6.1f│%-6.1f│%-6.1f│%-8.1f│%-8.1f│\n",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
				}
				printf("└───┴────┴───┴───┴───┴────┴────┘\n");
				printf("┌──────────────────────────────────┐\n");
				printf("│                               菜单                                 │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ① 计算每门课程的总分和平均分                    │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ② 成绩排序                                      │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   О  返回首页                                     │\n");
				printf("└──────────────────────────────────┘\n");
				while(1)
				{
					printf("%25s","操作:");
					scanf("%d",&n);
					break;
				}
				switch(n)
				{
				case 1:n=5;break;
				case 2:n=3;break;
				default:n=4;break;
				}
			}break;
		case 3:                    //
			{
				system("cls");
				printf("┌──────────────────────────────────┐\n");
				printf("│                      成绩排序                                      │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ① 学生的总分由高到低                            │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ② 学生的总分由低到高                            │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ③ 学号由小到大                                  │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   О  返回首页                                     │\n");
				printf("└──────────────────────────────────┘\n");
				while(1)
				{
					printf("%25s","操作:");
					scanf("%d",&n);
					break;
				}
				while(1)
				{
					switch(n)
					{
					case 1:
						{
							system("cls");
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
							printf("┌──────────────────────────────────┐\n");
							printf("│                      学生成绩排名(降序)                            │\n");
							printf("├───┬────┬───┬───┬───┬────┬────┬───┤\n");
							printf("│%-6s│%-8s│%-6s│%-6s│%-6s│%-8s│%-8s│%-6s│\n","姓名","学号","数学","物理","英语","总分","平均分","排名");
							for(i=0;i<f;i++)
							{
								printf("├───┼────┼───┼───┼───┼────┼────┼───┤\n");
								printf("│%-6s│%-8d│%-6.1f│%-6.1f│%-6.1f│%-8.1f│%-8.1f│%-6d│\n",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i],i+1);
							}
							printf("└──────────────────────────────────┘\n");
							printf("┌──────────────────────────────────┐\n");
							printf("│                      成绩排序                                      │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   ① 学生的总分由低到高                            │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   ② 学号由小到大                                  │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   О  返回首页                                     │\n");
							printf("└──────────────────────────────────┘\n");
							while(1)
							{
								printf("%25s","操作:");
								scanf("%d",&n);
								break;
							}
							switch(n)
							{
							case 1:n=2;break;
							case 2:n=3;break;
							default:n=4;break;
							}
						}break;
					case 2:
						{
							system("cls");
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
							printf("┌──────────────────────────────────┐\n");
							printf("│                      学生成绩排名(升序)                            │\n");
							printf("├───┬────┬───┬───┬───┬────┬────┬───┤\n");
							printf("│%-6s│%-8s│%-6s│%-6s│%-6s│%-8s│%-8s│%-6s│\n","姓名","学号","数学","物理","英语","总分","平均分","排名");
							for(i=0;i<f;i++)
							{
								printf("├───┼────┼───┼───┼───┼────┼────┼───┤\n");
								printf("│%-6s│%-8d│%-6.1f│%-6.1f│%-6.1f│%-8.1f│%-8.1f│%-6d│\n",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i],i+1);
							}
							printf("└──────────────────────────────────┘\n");
							printf("┌──────────────────────────────────┐\n");
							printf("│                      成绩排序                                      │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   ① 学生的总分由高到低                            │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   ② 学号由小到大                                  │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   О  返回首页                                     │\n");
							printf("└──────────────────────────────────┘\n");
							while(1)
							{
								printf("%25s","操作:");
								scanf("%d",&n);
								break;
							}
							switch(n)
							{
							case 1:n=1;break;
							case 2:n=3;break;
							default:n=4;break;
							}
						}break;
					case 3:
						{
							system("cls");
							for(i=0;i<f;i++)
							{
								for(j=0;j<f;j++)
								{
									if(b[i]>b[j])
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
							printf("┌──────────────────────────────┐\n");
							printf("│                      学生学号排序(升序)                    │\n");
							printf("├───┬────┬───┬───┬───┬────┬────┤\n");
							printf("│%-6s│%-8s│%-6s│%-6s│%-6s│%-8s│%-8s│\n","姓名","学号","数学","物理","英语","总分","平均分");
							for(i=0;i<f;i++)
							{
							    printf("├───┼────┼───┼───┼───┼────┼────┤\n");
								printf("│%-6s│%-8d│%-6.1f│%-6.1f│%-6.1f│%-8.1f│%-8.1f│\n",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
							}
							printf("└──────────────────────────────┘\n");
							printf("┌──────────────────────────────────┐\n");
							printf("│                      成绩排序                                      │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   ① 学生的总分由高到低                            │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   ② 学生的总分由低到高                            │\n");
							printf("├──────────────────────────────────┤\n");
							printf("│                   О 返回首页                                      │\n");
							printf("└──────────────────────────────────┘\n");
							while(1)
							{
								printf("%25s","操作:");
								scanf("%d",&n);
								break;
							}
							switch(n)
							{
							case 1:n=1;break;
							case 2:n=2;break;
							default:n=4;break;
							}break;
						}break;
					default:n=4;break;
					}
					if(n==4)
						break;
			   }
			}break;
		case 4:                                           //4
			{
				system("cls");
				menu();
				while(1)
				{
					printf("%25s","操作:");
					scanf("%d",&n);
					if(n<0||n>1)
						printf("%30s","错误!请重新输入\n");
					else
						break;
				}
				if(n==0)
					break;
				else
					n=1;
			}break;
		case 5:                     //5
			{  
				system("cls");
				for(i=0;i<f;i++)
				{
					sum1+=c[i];
					sum2+=d[i];
					sum3+=e[i];
				}
				av1=sum1/f;
				av2=sum2/f;
				av3=sum3/f;
				printf("┌────────────────────┐\n");
				printf("│            学生成绩表                  │\n");
				printf("├───┬────┬───┬───┬───┤\n");
				printf("│%-6s│%-8s│%-6s│%-6s│%-6s│\n","姓名","学号","数学","物理","英语");
				for(i=0;i<f;i++)
				{
					printf("├───┼────┼───┼───┼───┤\n");
					printf("│%-6s│%-8d│%-6.1f│%-6.1f│%-6.1f│\n",a[i],b[i],c[i],d[i],e[i]);
				}
				printf("├───┼────┼───┼───┼───┤\n");
				printf("│%-6s│%-8s│%-6.1f│%-6.1f│%-6.1f│\n","总分"," ",sum1,sum2,sum3);
				printf("├───┼────┼───┼───┼───┤\n");
				printf("│%-6s│%-8s│%-6.1f│%-6.1f│%-6.1f│\n","平均分"," ",av1,av2,av3);
				printf("└───┴────┴───┴───┴───┘\n");
				printf("┌──────────────────────────────────┐\n");
				printf("│                               菜单                                 │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ① 计算每个学生的总分和平均分                    │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   ② 成绩排序                                      │\n");
				printf("├──────────────────────────────────┤\n");
				printf("│                   О  返回首页                                     │\n");
				printf("└──────────────────────────────────┘\n");
				while(1)
				{
					printf("%25s","操作:");
					scanf("%d",&n);
					break;
				}
				switch(n)
				{
				case 1:n=2;break;
				case 2:n=3;break;
				default:n=4;break;
				}	
			}break;
		}
	}
}