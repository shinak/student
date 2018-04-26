/*#include<stdio.h>
int main()
{
	int a,b,n,f,i;
	scanf("%d",&n);
	while(n--)
	{
		i=0;
		scanf("%d",&f);
		a=f/2;
		b=f%2;
		if(b==1)
				i++;
		while(a!=0)
		{
			b=a%2;
			a=a/2;	
			if(b==1)
				i++;	
		}
		printf("%d\n",i);	
	}
	return 0;
} 
 
#include<stdio.h>
main()
{
	int n,m,s;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		s=0;
		while(m)
			m&=m-1,s++;
		printf("%d\n",s);
	}
}   */  
#include<stdio.h>
main()
{
	int s,m;
	scanf("%d",&m);
	s=0;
	printf("%d\n",m);
	while(m)
	{
		m=m&m-1,s++;
		printf("%d\n",m);
	}
	printf("%d\n",s);
}