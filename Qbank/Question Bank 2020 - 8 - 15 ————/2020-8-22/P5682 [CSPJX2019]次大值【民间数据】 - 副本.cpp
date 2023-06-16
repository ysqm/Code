# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 200000
# define reg register
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int n,a[N+5],cnt;

int main()
{
    n = Read();

    for(reg int i = 1; i <= n ; ++i) a[i] = Read();

    std::sort(a+1,a+n+1);

    for(reg int i = 1; i <= n ; ++i) if(a[i] != a[i-1]) a[++cnt] = a[i];

    if(cnt == 1) printf("-1");
    else printf("%d",std::max(a[n]%a[n-1],a[cnt-2]));

    return 0;
}
