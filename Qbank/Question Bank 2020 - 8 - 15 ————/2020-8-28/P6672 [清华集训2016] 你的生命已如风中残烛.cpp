# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define mod 998244353
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int n,m;
LL m1=2;

LL qp(LL x,int p=mod-2)
{
    LL res = 1;
    for(; p ; p>>=1,x = (x*x)%mod) (p&1) && (res=(res*x)%mod);
    return res;
}

int main()
{
    n = Read();

    for(reg int i = 1; i <= n ; ++i) m+= Read();

    for(reg int i = 3; i <= m ; ++i) m1 = m1*i%mod;
    
    printf("%lld",m1*qp(m-n+1)%mod);

    return 0;
}