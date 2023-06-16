#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#define rg register
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int N = 200,M = 2e3 + 100,base = 23;
int c[N][M];
int n,m;

ll ans = 0,t = 1;

ll Qpow(ll a,ll b)
{	ll ans = 1;
	while(b)
	{	if(b & 1)	ans *= a,ans %= mod,b--;
		a = a * a % mod;
		b >>= 1;
	}
	return ans % mod;
}
int sumk = 0,T[N];
int Max()
{	rg int mmax = 0;
	for(rg int i = 1;i <= m;++i)
		mmax = max(T[i],mmax);
	return mmax;
}
void dfs(int i)
{	int tt = Max();
	if(tt > (n >> 1))	return;
	if(tt && tt <= (sumk >> 1))
	{	ans += t;
		ans %= mod;
		//return;
	}
	if(i > n)
		return;
	for(int j = m;j >= 1;j--)
	{	if(c[i][j] && T[j] < i / 2 + 1)
		{	dfs(i + 1);
			++sumk,++T[j],t *= c[i][j],t %= mod;
			dfs(i + 1);
			--sumk,--T[j],t /= c[i][j],t %= mod;
		}
	}
}
int dp[N][M][N >> 1];

int main()
{	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{	for(int j = 1;j <= m;j++)
			scanf("%d",&c[i][j]);
	}
	if(n <= 20)
	{	dfs(1);
		printf("%lld",ans % mod / (n + 1) - 1);
		return 0;
	}
	dp[0][0][0] = 1;
	for(int i = 1;i <= n;i++)
	{	for(int j = 1;j <= m;j++)
		{	if(!c[i][j])	continue;
			for(int k = 0;k <= i;k++)
			{	if(k)
				{	for(int jj = 0;jj <= m;jj++)
						dp[i][j][k] += dp[i - 1][jj][k - 1] * c[i][j] % mod;
					dp[i][j][k] %= mod;
				}
				else
					dp[i][j][k] = 1;
			}
			//print();getchar();
		}
	}
	
	int ans = 0;
	for(int j = 1;j <= m;j++)
		for(int k = 0;k <= n;k++)
			ans += dp[n][j][k],ans %= mod;
	printf("%d",ans);
	return 0;
}
