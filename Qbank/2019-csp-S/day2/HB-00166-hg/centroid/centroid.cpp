# include <cstdio>
# include <cstring>
# include <iostream>
using namespace std;
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int t;
int n;
int te;
int sum[300010];
struct tu
{
	int u,v;
}e[600010];
int head[300010];
int lian[300010],l;
long long ans;
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		l=0;
		te=1;
		ans=0;
		memset(head,0,sizeof(head));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<n;++i)
		{
			int a=read(),b=read();
			sum[a]++;
			sum[b]++;
			e[i]=(tu){head[a],b};
			head[a]=i;
			e[i+n-1]=(tu){head[b],a};
			head[b]=i+n-1;
			if(i>=2&&te==1) if(a!=lian[l]) te=0;
			if(i==1) lian[++l]=a;
			if(te==1) lian[++l]=b;
		}
		if(te==1)
		{
			for(int i=1;i<n;++i)
			{
				int t1=(i+1)>>1,t2=(i+n+1)>>1;
				if(i%2==0) ans+=(lian[t1]+lian[t1+1]);
				else ans+=lian[t1];
				if((n-i)%2==0) ans+=(lian[t2]+lian[t2+1]);
				else ans+=lian[t2];
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<=n;++i) ans+=i*sum[i];
		printf("%lld\n",ans);
	}
	return 0;
}
