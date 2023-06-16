#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define N 5050

using namespace std;
typedef long long ll;

ll ans=0;
int n;
ll f[N][2];
ll a[N];
ll sum[N];

int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	memset(f,127,sizeof(f));
	int len,i,j,k;
	int n,t;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
//	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	f[0][0]=f[0][1]=0;
	for(i=1;i<=n;i++)
	{
		ll w1=f[i-1][0]-(f[i-1][1]*f[i-1][1]);
		ll tw=w1+(f[i-1][1]+a[i])*(f[i-1][1]+a[i]);
		if(tw<f[i][0]) f[i][0]=tw,f[i][1]=f[i-1][1]+a[i];
		ll sum=0;
		for(j=i;j<=n;j++) 
		{
			sum+=a[j];
			if(sum<f[i-1][1]) continue;
		 	ll w2=f[i-1][0]+sum*sum;
			if(w2<f[j][0]) f[j][0]=w2,f[j][1]=sum; 
		}
	}
	printf("%lld",f[n][0]);
	return 0;
}
