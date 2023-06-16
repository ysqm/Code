# include <set>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 1024
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
template<class T>
inline T Read()
{
    register T x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

int f[N+5][N+5],n,a[N+5];

int main()
{
    freopen("ysqm.in","r",stdin);
	for(int T = Read<int>(); T ; T--)
    {
        n = Read<int>();
        for(int i = 1; i <= n ; ++i) f[0][i] = Read<int>();
        for(int i = 1; i <= n ; ++i)
            for(int j = 1; j <= 1024 ; ++j)
                f[j][i] = f[0][i]^j;
        for(int i = 0; i <= 1024 ; ++i) std::sort(f[i]+1,f[i]+n+1);
        for(int i = 1; i <= 1024 ; ++i)
        {
            for(int j = 1; j <= n ; ++j) 
                if(f[i][j] != f[0][j]) goto part;
            printf("%d\n",i);
            goto part1;
            part:;
        }
        puts("-1");
        part1:;
    }
    return 0;
}
