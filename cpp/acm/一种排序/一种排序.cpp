#include<iostream>
using namespace std;
int main()
{
	int a[1000][3];
	int j,n,m,t,l,k,f;
	cin>>n;
	while(n--)
	{
		cin>>m;
		for(j=0;j<m;j++)
		{
			for(f=0;f<3;f++)
				cin>>a[j][f];
		}
		for(j=0;j<m;j++)
		{
			if(a[j][1]<a[j][2])
			{
				t=a[j][1];
				a[j][1]=a[j][2];
				a[j][2]=t;
			}
		}
		for(j=0;j<m;j++)
		{
			for(k=j+1;k<m;k++)
			{
				for(f=0,l=0;f<3;f++)
				{
					if(a[j][f]==a[k][f])
						l++;
				}
				if(l==3)
				{
					for(t=k;t<m;t++)
					{
						for(f=0,l=0;f<3;f++)
							a[t][f]=a[t+1][f];
					}
					m--;
				}
			}
		}
		for(j=0;j<m;j++)         
		{
			l=j;
			for(k=j+1;k<m;k++)
			{
				if(a[l][0]>a[k][0])
					l=k;
				if(a[l][0]==a[k][0])
				{
					if(a[l][1]>a[k][1])
						l=k;
					if(a[l][1]==a[k][1])
					{
						if(a[l][2]>a[k][2])
							l=k;
					}
				}
			}
			for(f=0;f<3;f++)
			{
		     	t=a[j][f];
		    	a[j][f]=a[l][f];
		    	a[l][f]=t;
			}
		}
		for(j=0;j<m;j++)
			cout<<a[j][0]<<' '<<a[j][1]<<' '<<a[j][2]<<endl;
	}
	return 0;
}
/*
#include<iostream>

#include<set>

#include<iterator>

using namespace std;

struct Rect

{
		  
	int num,length,width;
	
	
				
};

bool operator<(const Rect& r1,const Rect& r2)

{
	
	return r1.num<r2.num || r1.num==r2.num && r1.length<r2.length ||r1.num==r2.num&&r1.length==r2.length &&r1.width<r2.width;
	
}

istream& operator>>(istream& in,Rect& r)

{
	
	in>>r.num;
	
	int a,b;
	
	cin>>a>>b;
	
	r.length=max(a,b);
	
	r.width=min(a,b);
	
	return in;
	
}

ostream& operator<<(ostream& out,const Rect& r)

{
	
	return out<<r.num<<" "<<r.length<<" "<<r.width;
	
}

int main()

{
	
	int num;
	
	cin>>num;
	
	while(num--)
		
	{
		
		set<Rect> rs;
		
		Rect r;
		
		int n;
		
		cin>>n;  
		
		while(n--)
			
		{
			
			cin>>r;
			
			rs.insert(r);
			
		}
		
		copy(rs.begin(),rs.end(),ostream_iterator<Rect>(cout,"\n"));
		
		
		
	}
	
	
	
	
	
}