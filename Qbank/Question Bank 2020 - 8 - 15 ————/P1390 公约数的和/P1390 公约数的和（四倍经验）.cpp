# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 2000000
# define LL long long

bool vis[N+5];
LL f[N+5],g[N+5]; 
int phi[N+5],p[N+5],tot;

inline void OULA(const int n)
{
    vis[1] = true;phi[1] = 0; 
    for(reg int i = 2; i <= n; ++i)
	{
		if(!vis[i])
		{
			p[++tot] = i;
			phi[i] = i-1;
		}
		for(reg int j = 1 ; j <= tot && i*p[j] <= n ; ++j)
		{
			vis[i*p[j]] = 1;
			if(i % p[j] == 0) {phi[i*p[j]] = phi[i] * p[j];break;}
			else phi[i*p[j]] = phi[i] * phi[p[j]];
		}
	}
	
	for(reg int i = 1; i*i <= n ; ++i)
	{
		f[i*i] += i*phi[i];
		for(reg int j = i+1; i*j <= n ; ++j) f[i*j] += i*phi[j] + j*phi[i];
	}
	
	for(reg int i = 1; i <= n ; ++i) g[i] = g[i-1]+f[i];
}

LL ans;
int n;

int main()
{
	OULA(N);
	
    while(scanf("%d",&n) && n) printf("%lld\n",g[n]);

    return 0;
}
