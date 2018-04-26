//将十进制100转化为十六进制；
#include<stdio.h>
#include<math.h>
int main()
{
	int x,n,m,f;
	float i=0.0;
	n=100/16;
	m=100%16;
	while(n!=0)
	{
		x=m;
		m=n%16;
		n=n/16;
		i++;
		f=m*pow(10,i)+x*pow(10,--i);
	}
	printf("%d\n",f);
	return 0;
}



