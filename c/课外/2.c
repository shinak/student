#include<stdio.h>
#include<math.h> 
int main()
{
	int a,n,sum=0,sn=0,i=0;
	float b;
	printf("输入a,n的值:");
	scanf("%d%d",&a,&n);
	n=n-1;
	while(i<=n)
	{
		b=pow(10,i);  //赋值  b=10^i
		a=a*b;        //执行  a=a*10^i
		sum+=a;       //执行  sum=sum+a
		sn+=sum;      //执行  sn=sn+sum
		i++;
		a=a/b;
	}
	printf("sn=%d\n",sn);
	return 0;
}