# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
# define LL long long
# define reg register
# define N 10000000
//# define N 1000
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

LL ans[N+5],diff1[N+5],diff2[N+5],d;
int n,m;

int main()
{
    //freopen("1.in","r",stdin);

    n = Read();m = Read();

    reg LL e,s;

    for(reg int i = 1,l,r; i <= m ; ++i)
    {  
        l = Read();r = Read();s = Read();e = Read();
        diff1[l] += s;diff1[r+1] -= e;
        e = (e-s)/(r-l);
        diff2[l+1] += e;diff2[r+1] -= e;
    }

    e = 0;

    for(reg int i = 1; i <= n ; ++i) diff1[i] += (e += diff2[i]);

    e = 0;

    for(reg int i = 1; i <= n ; ++i) ans[i] += (e += diff1[i]);

    s = e = 0;

    for(reg int i = 1; i <= n ; ++i)
    {
        (ans[i] > e) && (e = ans[i]);
        s ^= ans[i];
    }

    printf("%lld %lld",s,e);

    return 0;
}