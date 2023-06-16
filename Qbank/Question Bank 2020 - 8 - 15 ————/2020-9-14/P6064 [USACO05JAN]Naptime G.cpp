# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 3830
# define max std::max

inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

inline int Max(const int x,const int y){return x > y ? x : y;}
inline int Min(const int x,const int y){return x < y ? x : y;}

int n,m,f[2][N+5][2],a[N+5],ans;

void DP()
{
    for(int i = 2; i <= n ; ++i)
	{
		f[i&1][0][0] = f[(i^1)&1][0][0];
		for(int j = 1; j <= m ; ++j)
        {
            f[i&1][j][0] = max(f[(i^1)&1][j][0],f[(i^1)&1][j][1]);
            f[i&1][j][1] = max(f[(i^1)&1][j-1][0],f[(i^1)&1][j-1][1]+a[i]);
        }
	}
}

int main()
{
    n = Read();m = Read();
    for(int i = 1; i <= n ; ++i) a[i] = Read();
    if(m == 0) return printf("0\n"),0;
    memset(f,-0x3f,sizeof(f));
    f[1][0][0] = f[1][1][1] = 0;
    DP();
    ans = max(f[n&1][m][0],f[n&1][m][1]);
    memset(f,-0x3f,sizeof(f));
    f[1][1][1] = a[1];
    DP();
    ans = max(ans,f[n&1][m][1]);
    printf("%d\n",ans);
    return 0;
}