#include <iostream>
using namespace std;
/*void main()
{
	int a[10]={2,8,9,5,5,6,5,8,7,5};
	int i,j,l,n=10;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		if(a[i]==a[j])
		{
			for(l=j;l<n;l++)
				a[l]=a[l+1];
			n--;
			j--;
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
}
void main()
{
	int a[5]={1,1,3,4,6};
	int b[5]={0,2,2,6,8};
	int c[10];
	int i=0,j=0,l=0,n=5,m=5;
	for(;l<n+m;l++)
	{
		if(i==n)
		{
			c[l]=b[j];
			j++;
		}
		else if(j==n)
		{
			c[l]=a[i];
			i++;
		}
		else if(a[i]<=b[j])
		{
			c[l]=a[i];
			i++;
		}
		else if(a[i]>b[j])
		{
			c[l]=b[j];
			j++;
		}
	}

	for(i=0;i<l;i++)
		cout<<c[i]<<' ';
	cout<<'\n';
}*/
void main()
{	int i,j,f;
	int a[11]={1,2,3,4,5,6,7,8,9,10,11};     //3 4  5 6 7
	         //0,1,2,3,4,5,6,7,8, 9,10
	int n=1,m=11,l=11;
	for(i=0;i<l;i++)
		if(a[i]>=n)
			break;
	for(j=l-1;j>=0;j--)
		if(a[j]<=m)  //可优化
		{
			f=j+1;   
			
			l=l-(j-i+1);  
			break;
		}
	cout<<f<<l<<endl;
	for(;i<f;i++,j++)
		a[i]=a[j+1];
	cout<<i<<j<<endl;
	for(;i<l;i++,j++)
	{
		a[i]=a[j+1];
	}
	for(i=0;i<l;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
}
/*void main()
{
	int i;
	int a[11]={3,5,4,40,10,3,5,6,7,30,0};     //3 4  5 6
	int n=3,m=6,l=11;
	for(int i=0;i<l;i++)
	{
		if(a[i]>=n&&a[i]<=m)
		{
			for(int j=i;j<l;j++)
				a[j]=a[j+1];
			l--;
			i--;
		}
	}
	for(i=0;i<l;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
}
void main()
{	
	int i=0,j,l,f,n=11;
	int a[11]={3,5,4,40,10,3,5,0,0,30,0};

	do
	{
	for(j=i+1;j<n;j++)   //判断最小值
	{
		if(a[i]>a[j])
			i=j;
	}
	for(j=i+1,l=0;j<n;j++)   //检查最小值是否重复
	{
		if(a[i]==a[j])
			l++;
	}
	cout<<a[i]<<endl;
	if(a[i]==a[j-1])   //最后元素为最小值，删除
		n--;
	else
		a[i]=a[n-1];    //将最后元素填补最小元素所在位置 
	}while(l!=0);
	
	
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
}
*/