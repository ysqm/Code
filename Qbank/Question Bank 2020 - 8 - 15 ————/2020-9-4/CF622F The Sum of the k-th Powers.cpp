# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define reg register
# define int long long
const int N = 1e6;
const LL mod = 1e9+7;

LL Pre[N+45],Suf[N+45],fac[N+45];
int y[N+45],n,k,m,ans;

inline int Mod(const int x){return x < mod ? x : x-mod;}

inline int qpow(LL x,int p=1e9+5)
{
    reg LL res = 1;
    for(; p ; p >>= 1,x = (x*x)%mod) if(p&1) res = (res*x)%mod;
    return res;
}

signed main()
{
    scanf("%lld%lld",&n,&k);
    m = k+2;fac[0] = Pre[0] = Suf[m+1] = y[1] = 1;

    for(reg int i = 2; i <= m ; ++i) y[i] = Mod(y[i-1]+qpow(i,k));

    for(reg int i = 1; i <= m ; ++i) Pre[i] = Pre[i-1]*(n-i)%mod;

    for(reg int i = m; i >= 1 ; --i) Suf[i] = Suf[i+1]*(n-i)%mod;

    for(reg int i = 1; i <= m ; ++i) fac[i] = (fac[i-1]*i)%mod;

    for(reg int i = 1; i <= m ; ++i)
    ans = Mod(Mod(ans + ((m-i)&1 ? -1LL : 1LL) * ((Pre[i-1]*Suf[i+1]%mod*qpow(fac[i-1]*fac[m-i]%mod)%mod*y[i]%mod)))+mod); 

    printf("%lld",(ans+mod)%mod);

    return 0;
}
