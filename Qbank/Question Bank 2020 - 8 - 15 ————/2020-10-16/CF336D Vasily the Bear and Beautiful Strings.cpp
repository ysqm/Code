# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <iostream>
# define LL long long
# define N 200000
inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

const LL mod = 1000000007;

LL qpow(LL x,int p = mod-2)
{
    LL res = 1;
    for(; p ; p>>=1,x = (x*x)%mod) if(p&1) res = res*x%mod;
    return res;
}

LL fac[N+5],inv[N+5],ans;

LL Cn(const LL n,const LL m){return fac[n] * inv[n-m] % mod * inv[m] % mod;}

int n,m,g;


int main()
{
    scanf("%d%d%d",&n,&m,&g);
    fac[0] = 1;
    for(int i = 1; i <= n+m ; ++i) fac[i] = fac[i-1]*i%mod;
    inv[n+m] = qpow(fac[n+m]);
    for(int i = n+m-1; i >= 0 ; --i) inv[i] = inv[i+1]*(i+1)%mod;
    if(n == 0) return printf("%d\n",m == 1 ? g : g^1),0;
    if(m == 0) return printf("%d\n",n & 1 ? g^1 : g),0;
    for(int i = 0; i <= n ; i += 2) ans = (ans + Cn(n+m-1-i,m-1))%mod;
    m == 1 && (ans = ((n&1) ? (ans + 1) % mod : (ans - 1 + mod) % mod));
    if(g) ans = (Cn(n+m,n)-ans+mod)%mod; 
    printf("%lld\n",ans);
    return 0;
}
