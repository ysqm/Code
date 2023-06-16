# include <map>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define LL long long
# define reg register
const LL mod = 1e9+7;

int T;
LL a[55],n,m,k,Fac[55],Pre[55],Suf[55],f[55],ans;

inline int Mod(const int x){return x < mod ? x : x-mod;}

inline int qpow(LL x,int p=1e9+5)
{
    reg LL res = 1;
    for(; p ; p>>=1,x = (x*x)%mod) if(p&1) res = res*x%mod;
    return res; 
}

inline int Lagrange(const int x)
{
    if(x <= k) return f[x];
    reg LL res = 0;Suf[k+1] = 1;
    for(reg int i = 1; i <= k ; ++i) Pre[i] = Pre[i-1]*(x-i)%mod;
    for(reg int i = k; i >= 1 ; --i) Suf[i] = Suf[i+1]*(x-i)%mod;
    for(reg int i = 1; i <= k ; ++i) res = (res + ((((k-i)&1) ? -1LL : 1LL) * (Pre[i-1]*Suf[i+1]%mod * qpow(Fac[i-1]*Fac[k-i]%mod))%mod * f[i])%mod)%mod;
	return Mod(res+mod);
}

int main()
{
    Fac[0] = Pre[0] = f[1] = 1;
    for(reg int i = 1; i <= 54 ; ++i) Fac[i] = Fac[i-1]*i%mod;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);k = m+3;
        for(reg int i = 1; i <= m ; ++i) scanf("%d",a+i);
        std::sort(a+1,a+m+1);
        while(a[m] == n){m--;n--;k--;}
        for(reg int i = 2; i <= k ; ++i) f[i] = (f[i-1]+qpow(i,m+1))%mod;
        for(reg int i = 1; i <= m+1 ; ++i)
        {
            ans = Mod(ans+Lagrange(n-a[i-1]));
            int aiaj = 0;
            for(reg int j = i; j <= m; ++j) aiaj = Mod(aiaj+qpow(a[j]-a[i-1],m+1));
            ans = Mod(Mod(ans+mod-aiaj)+mod);
        }
        printf("%d\n",ans);ans = 0;
    }
    return 0;
}
