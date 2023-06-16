# include <ctime>
# include <queue>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

const int N = 3e5;

struct edge
{
    int Next,to;

    edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[(N<<1) + 42];
int head[N + 42],edge_tot = 1;

inline void add_edge(const int u,const int v)
{
    e[++edge_tot] = edge(head[u],v);

    head[u] = edge_tot;

    e[++edge_tot] = edge(head[v],u);

    head[v] = edge_tot;
}

inline int Max(const int x,const int y){return x > y ? x : y;}

bool vis[N+5];
int n,dp[N+5];

void dfs(const int u,const int fa,const int x)
{
    int cnt=0;
    for(reg int i = head[u]; i ; i = e[i].Next)
        if(e[i].to != fa)
        {
            dfs(e[i].to,u,x);
            cnt += dp[e[i].to] + 1;
        }
    dp[u] = Max(cnt-x,0);
}

inline bool check(const int x)
{
    dfs(1,1,x);
    return dp[1] == 0;
}

int main()
{
    n = Read();

    for(reg int i = 2; i <= n ; ++i) add_edge(Read(),Read());

    reg int l = 0,r = n,mid;

    while(l < r)
    {
        mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    printf("%d",l);

    return 0;
}
