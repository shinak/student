#include<stdio.h>
#include<string.h>
void menu()
{
	printf("________________________________________________________________________________\n");
	printf("                               ѧ���ɼ�����ϵͳ\n");
	printf("________________________________________________________________________________\n");
	printf("|%-10s|%-12s|%-10s|%-10s|%-10s|%-10s|%-10s|\n","����","ѧ��","��ѧ","����","Ӣ��","�ܷ�","ƽ����");
	printf("�˵�:\n");
	printf("1��¼��ÿ��ѧ����ѧ�ź͸��ƿ��Գɼ�;\n");
	printf("2������ÿ�ſγ̵��ֺܷ�ƽ����\n");
	printf("3������ÿ��ѧ�����ֺܷ�ƽ����\n");
	printf("4����ÿ��ѧ�����ܷ��ɸߵ����ų����α�\n");
	printf("5����ÿ��ѧ�����ܷ��ɵ͵����ų����α�\n");
	printf("6����ѧ����С�����ų��ɼ���\n");
	printf("7����ѧ�Ų�ѯѧ�����������ƿ��Գɼ�\n");
	printf("8�������㡢���á��еȡ����񡢲�����5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Ͱٷֱ�\n");
	printf("9�����ÿ��ѧ����ѧ�š����Ƴɼ����ܷ֡�ƽ����\n");
	printf("10�����ÿ�ſγ̵��ֺܷ�ƽ����\n");
	printf("0���˳�ϵͳ\n");
}
void frist()
{
	printf("________________________________________________________________________________\n");
	printf("                               ѧ���ɼ�����ϵͳ\n");
	printf("________________________________________________________________________________\n");
	printf("|%-10s|%-12s|%-10s|%-10s|%-10s|%-10s|%-10s|","����","ѧ��","��ѧ","����","Ӣ��","�ܷ�","ƽ����");
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
		printf("����:");
		scanf("%d",&n);
		if(n==0)
			break;
		if(n<0||n>10)
			printf("����!������:");
		else switch(n)
		{
			case 1:
				{
					while(1)
					{
						printf("����༶������:");
						scanf("%d",&f);
						if(f>30)
							printf("����������");
						else
							break;
					}
					for(i=0;i<f;i++)
						scanf("%s%d%f%f%f",&a[i],&b[i],&c[i],&d[i],&e[i]);
					printf("��һ��");
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
					printf("��һ��");
				};break;
			case 3:
				{
					for(i=0;i<f;i++)
					{
						sum4[i]=c[i]+d[i]+e[i];
						av4[i]=sum4[i]/3;
					}
					printf("��һ��");
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
						printf("��һ��");
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
					printf("��һ��");
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
					printf("��һ��");
				};break;
			case 7:
				{
					printf("��Ҫ��ѯ��ѧ��:");
					scanf("%d",&k);
					for(i=0;i<f;i++)
					{
						if(k==b[i])
							printf("|%-10s|%-12d|%-10.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
					}
					printf("��һ��");
				   };break;
			case 8:;break;
			case 9:
				{
					frist();
					for(i=0;i<f;i++)
					     printf("|%-10s|%-12d|%-10.1f|%-10.1f|%-10.1f|%-10.1f|%-10.1f|",a[i],b[i],c[i],d[i],e[i],sum4[i],av4[i]);
					printf("��һ��");
				};break;
			case 10:
				{
					printf("|%-10s|%-12s|","�ܷ�"," ");
					printf("%-10.1f|%-10.1f|%-10.1f|\n",sum1,sum2,sum3);
					printf("|%-10s|%-12s|","ƽ����"," ");
					printf("%-10.1f|%-10.1f|%-10.1f|\n",av1,av2,av3);
					printf("��һ��");
				};break;	
		}
	}
	return 0;
}
