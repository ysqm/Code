# include <cstdio>
# define reg //register
# define N 500

inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9') ch = getchar();

    while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = getchar();}

    return x;
}

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

bool vis[N+5][N+5];
int r[N+5][N+5],l[N+5][N+5],a[N+5][N+5],n,m,ans;

inline int Min(const int x,const int y){return x < y ? x : y;}
inline int Max(const int x,const int y){return x > y ? x : y;}

void dfs(const int sx,const int sy)
{
    vis[sx][sy] = true;

    int x,y;

    for(reg int i = 0; i <= 3 ; ++i)
    {
    	x = sx+dx[i];y = sy+dy[i];
    	if(((x) <= n) && x >= 1 && (y) <= m && (y >= 1) && a[sx][sy] > a[x][y])
        {
            if(!vis[x][y]) dfs(x,y);
            l[sx][sy] = Min(l[sx][sy],l[x][y]);
            r[sx][sy] = Max(r[sx][sy],r[x][y]);
        }
	}
        
}

int main()
{
    n = Read();m = Read();

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 1; j <= m ; ++j)
            a[i][j] = Read();

    for(reg int i = 1; i < n ; ++i)
        for(reg int j = 1; j <= m ; ++j)
            l[i][j] = 0x3f3f3f3f;

        for(reg int j = 1; j <= m ; ++j)
            r[n][j] = l[n][j] = j;

    for(reg int i = 1; i <= m ; ++i) if(!vis[1][i]) dfs(1,i);

    for(reg int i = 1; i <= m ; ++i) ans += (!vis[n][i]);

    if(ans) return printf("0\n%d",ans),0;
    else
    {
        register int L = 1,mr = 0;

        while(L <= m)
        {
            mr = 0;
            for(register int i = 1; i <= m ; ++i) (l[1][i] <= L) && (mr = Max(mr,r[1][i]));

            ++ans;
            L = mr+1;
        }
    }
    
    printf("1\n%d",ans);

    return 0;
}
