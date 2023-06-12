#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#define N 120
#define M 2050
#define Mod 998244353

using namespace std;
typedef long long ll;

int n,m;
ll ans=0,tans=0;
ll a[N][M];
ll sum[N],f[N];
ll dp[N];
ll jc[N];
int book[M];
//queue<int> q;

void dfs(int lim,int x,int sum)
{
	int i;
	//printf("%d %d %d %d\n",lim,x,sum,tans);
	if(sum==lim)
	{
		ans+=tans;
		return;
	}
	for(i=1;i<=m;i++)
	{
		if(!a[x][i] || (book[i]+1)>(lim/2)) continue;
		tans*=a[x][i];tans%=Mod;book[i]++;
		dfs(lim,x+1,sum+1);
		tans/=a[x][i];tans%=Mod;book[i]--;
	}
	if(n-x+sum>=lim) dfs(lim,x+1,sum);
	return;
}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	/*for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			sum[i]+=a[i][j],sum[i]%=Mod;
	//for(i=1;i<=n;i++) f[i]=f[i-1]+sum[i],f[i]%=Mod;*/
	for(i=2;i<=n;i++) 
	{
		memset(book,0,sizeof(book));
		tans=1;
		dfs(i,1,0);
	}
	/*jc[0]=1;
	for(i=1;i<=n;i++) jc[i]=jc[i-1]*i,jc[i]%=Mod;
	dp[0]=dp[1]=f[n];
	//printf("%lld\n",dp[1]);
	for(i=1;i<=m;i++)
	{
		
	}
	for(k=3;k<=n;k++)
	{
		dp[k]=dp[k-1]*f[n];dp[k]%=Mod;
		//printf("%lld\n",dp[k]);
		for(i=1;i<=n;i++)
		{
			ll w;
			w=sum[i]*sum[i];w%=Mod;
			printf("%lld\n",w);
			w*=(f[i-1]+f[n]-f[i]);w%=Mod;
			printf("%lld\n",w);
			w*=jc[k-1];w%=Mod;
			printf("%lld\n",w);
			//printf("%lld\n",w);
			dp[k]-=w;dp[k]=(dp[k]+Mod)%Mod;
			//printf("%lld\n",dp[k]);
			break;
		}
		dp[k]/=k;
		//dp[k]-=(dp[k-(k/2+1)]);
		ans+=(dp[k]-dp[k-(k/2+1)]);
		ans%=Mod;
		break;
	}*/
	printf("%lld",ans);
	return 0;
}
