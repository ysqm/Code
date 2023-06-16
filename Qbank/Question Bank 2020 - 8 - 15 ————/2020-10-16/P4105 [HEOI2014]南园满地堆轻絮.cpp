# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <iostream>
# define N 5000000
# define LL long long

LL mod,Sa,Sb,Sc,Sd;
int n,Mountain,x1,x2,x3,ans;

inline int F(const LL x){return (Sa*x%mod*x%mod*x%mod+Sb*x%mod*x%mod+Sc*x%mod+Sd)%mod;}

int Input()
{
    scanf("%d%lld%lld%lld%lld%d%lld",&n,&Sa,&Sb,&Sc,&Sd,&x2,&mod);
    if(Sa < 0) Sa %= mod;
    if(Sb < 0) Sb %= mod;
    if(Sc < 0) Sc %= mod;
    if(Sd < 0) Sd %= mod;
    Mountain = x2;
    for(int i = 2; i <= n ; ++i)
    {
        x3 = (F(x1)+F(x2))%mod;
        if(Mountain - x3 > ans) ans = Mountain - x3;
        if(Mountain < x3) Mountain = x3;
        x1 ^= x2 ^= x1 ^= x2;
        x3 ^= x2 ^= x3 ^= x2;
    }
    return (ans+1)/2;
}

int main()
{
    freopen("ysqm.in","r",stdin);
    printf("%d",Input());
    return 0;
}
