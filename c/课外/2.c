#include<stdio.h>
#include<math.h> 
int main()
{
	int a,n,sum=0,sn=0,i=0;
	float b;
	printf("����a,n��ֵ:");
	scanf("%d%d",&a,&n);
	n=n-1;
	while(i<=n)
	{
		b=pow(10,i);  //��ֵ  b=10^i
		a=a*b;        //ִ��  a=a*10^i
		sum+=a;       //ִ��  sum=sum+a
		sn+=sum;      //ִ��  sn=sn+sum
		i++;
		a=a/b;
	}
	printf("sn=%d\n",sn);
	return 0;
}