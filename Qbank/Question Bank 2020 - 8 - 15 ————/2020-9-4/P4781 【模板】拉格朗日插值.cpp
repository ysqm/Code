# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 2000
# define LL long long


const LL mod = 998244353;
LL l = 1,w[N+5];
int n,x[N+5],y[N+5],k,ans = 0;

inline LL qpow(LL x,int p=mod-2)
{
    reg LL res = 1;
    for(; p ; p>>=1,x = (x*x)%mod) if(p&1) res = (res*x)%mod;
    return res;
}

inline void exgcd(const int a,const int b,int &x,int &y)
{
    if(b == 0) x = 1,y = 0;
    else exgcd(b%a,a,y,x),y -= b/a*x;
}

int main()
{
    scanf("%lld%lld",&n,&k);

    for(reg int i = 1; i <= n ; ++i) scanf("%lld%lld",x+i,y+i);

    for(reg int i = 1; i <= n ; ++i) l = (l*(k-x[i]))%mod;

    for(reg int i = 1; i <= n ; ++i)
    {
        w[i] = 1;
        for(reg int j = 1; j <= n ; ++j) if(i != j) w[i] = (w[i]*(x[i]-x[j]))%mod;
    }

    for(reg int i = 1; i <= n ; ++i) ans = (ans+(qpow(((k-x[i])*w[i])%mod)*y[i]%mod))%mod;

    printf("%lld",((l*ans%mod)+mod)%mod);

    return 0;
}
