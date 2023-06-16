# include <cstdio>
# define LL long long

LL mod,k,L,s,w;

inline LL qpow(register LL x,register int p)
{
    register LL res = 1;
    for(; p ; p >>=1,x = (x*x)%mod) if(p&1) res = res*x%mod;
    return res; 
}

int main()
{
    scanf("%lld%lld%lld%lld%lld",&k,&L,&mod,&s,&w);

    k %= mod;
    if(k < 2) k += mod;
    if(L == 1) printf("%lld",w ? 1 : k);
    else if(s == 0) printf("%lld",k*(k-1)%mod*qpow(k-2,L-2)%mod);
    else printf("%lld",(k-1)*qpow(k-2,L-2)%mod);
    return 0;
}
