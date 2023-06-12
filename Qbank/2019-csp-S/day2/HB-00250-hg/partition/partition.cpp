# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;
int n;
int x[500001];
long long ans=0;
long long keep=0;
int main()
{
	int tp;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d%d",&n,&tp);
	for(int i=1;i<=n;i++)
	scanf("%d",&x[i]);
	
	bool flag=1;
	for(int i=1;i<n;i++)
	{
		keep=0;
		if(x[i]<=x[i+1])
		{
			continue;
		}
		else
		{
			int M=i;
			for(i++;;i++)
			{
				keep+=x[i];
				x[i]=0;
				if(i==n)
				{
					x[M]+=keep;
					break;
				}
				if(x[M]+keep<=x[i+1])
				{
					x[M]+=keep;
					break;
				}
				if(x[M]<=x[i+1]+keep)
				{
					x[i+1]+=keep;
					break;
				}
			}
		}
	}
	if(x[n]<x[n-1])
	{
		x[n-1]+=x[n];
		x[n]=0;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=x[i]*x[i];
	}
	cout<<ans;
	return 0;
}
