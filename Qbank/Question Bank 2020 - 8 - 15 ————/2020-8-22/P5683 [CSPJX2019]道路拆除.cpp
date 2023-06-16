# include <ctime>
# include <queue>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 3000
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

std::queue<int> q;
int n,dis[3][N+5],m,s1,t1,s2,t2,ans;

inline void BFS(const int Type)
{
    reg int u = (Type  == 0 ? 1 : (Type == 1 ? s1 : s2));
    q.push(u);dis[Type][u] = 0;

    while (q.size())
    {
        int u = q.front();q.pop();
        
        for(reg int i = head[u]; i ; i = e[i].Next)
            if(dis[Type][e[i].to] == -1)
            {
                dis[Type][e[i].to] = dis[Type][u] + 1;
                q.push(e[i].to);
            }
    }
}

inline int Min(const int a,const int b){return a < b ? a : b;}

int main()
{
    n = Read();m = Read();

    memset(dis,-1,sizeof(dis));

    for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read());

    s1 = Read();t1 = Read();s2 = Read();t2 = Read();ans = 0x7f7f7f7f;
    BFS(0);BFS(1);BFS(2);

    for(reg int i = 1; i <= n ; ++i)
        if(dis[0][i] != -1 && dis[1][i] != -1 && dis[2][i] != 0) 
            ans = Min(ans,dis[0][i]+dis[1][i]+dis[2][i]);

    if(ans > t1+t2) puts("-1");
    else printf("%d\n",ans);
    return 0;
}
