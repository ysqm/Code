# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
const int N = 100;

# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int a[N+5],t[N+5],n,c[N+5],d[N+5];

int main()
{
    n = Read();

    for(reg int i = 1; i <= n ; ++i) a[i] = Read();

    for(reg int i = 1; i <= n ; ++i) t[i] = Read();

    if(a[1] != t[1] || a[n] != t[n]) puts("No");
    else
    {
        for(reg int i = 2; i <= n; ++i) c[i] = a[i]-a[i-1];
        for(reg int i = 2; i <= n; ++i) d[i] = t[i]-t[i-1];

        std::sort(c+2,c+n+1);
        std::sort(d+2,d+n+1);

        for(reg int i = 2; i < n; ++i)
            if(c[i] != d[i]){puts("No");return 0;}

        puts("Yes");
    }

    return 0;
}