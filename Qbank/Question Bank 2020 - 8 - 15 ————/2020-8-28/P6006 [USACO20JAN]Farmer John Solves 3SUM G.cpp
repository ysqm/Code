# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 5000
# define LL long long
//# define MaxN 10
# define MaxN 1000000
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0,f = 1;char ch = Gc;

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = Gc;}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return f < 0 ? ~x+1 : x;
}

int n,m,a[N+5],bucket[(MaxN<<1)+5];
LL f[N+5][N+5];

int main()
{
    n = Read();m = Read();

    for(reg int i = 1; i <= n ; ++i) a[i] = Read()+MaxN;

    for(reg int i = 1; i <= n ; ++i)
    {
        for(reg int j = i+1; j <= n ; ++j)
        {
            if(j > i+1 && a[i]+a[j] >= MaxN && a[i]+a[j] <= 3*MaxN) f[i][j] = bucket[3*MaxN-a[i]-a[j]];
            ++bucket[a[j]];
        }
        for(reg int j = i+1; j <= n ; ++j) --bucket[a[j]];
    }

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 1; j <= n ; ++j)
            f[i][j] = f[i-1][j] + f[i][j-1] + f[i][j] - f[i-1][j-1];

    register int l,r;

    while(m--)
    {
        scanf("%d%d",&l,&r);
        printf("%lld\n",f[r][r] - f[r][l-1] - f[l-1][r] + f[l-1][l-1]);
    }

    return 0;
}
