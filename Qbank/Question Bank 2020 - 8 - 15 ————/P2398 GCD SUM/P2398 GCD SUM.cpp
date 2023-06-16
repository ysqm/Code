# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 100000
# define LL long long

bool vis[N+5];
int phi[N+5],p[N+5],tot;

inline void OULA()
{
    vis[1] = true;phi[1] = 1; 
    for(reg int i = 2; i <= N; ++i)
	{
		if(!vis[i])
		{
			p[++tot] = i;
			phi[i] = i-1;
		}
		for(reg int j = 1 ; j <= tot && i * p[j] <= N ; ++j)
		{
			vis[i*p[j]] = 1;
			if(i % p[j] == 0) {phi[i*p[j]] = phi[i] * p[j];break;}
			else phi[i*p[j]] = phi[i] * phi[p[j]];
		}
	}
}

LL ans;
int n;

int main()
{
    OULA();

    scanf("%d",&n);

    for(int i = 1,j; i <= n ; ++i)
    {
        for(j = 1; j * j < i ; ++j)
            if(i%j == 0) ans += j*(LL)phi[i/j]+(i/j)*(LL)phi[j];
        if(j*j == i) ans += j*(LL)phi[j];
    }
        
    printf("%lld\n",(ans<<1)-((n*(LL)(n+1))>>1));

    return 0;
}
