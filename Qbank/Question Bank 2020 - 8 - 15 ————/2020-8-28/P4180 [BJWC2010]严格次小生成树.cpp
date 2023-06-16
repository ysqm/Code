# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define M 300000
# define N 100000
# define Max_Step 10
# define Gc /*getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1<<15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;
    
    while(ch < '0' || ch > '9') ch = Gc;

    while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}

    return x;
}

struct EDGE
{
    bool Used;
    int u,v,wi;
    EDGE(const int Wi=0,const int V=0,const int U=0,const bool Used_=false):u(U),v(V),wi(Wi),Used(Used_){}
    inline bool operator < (const EDGE& b)const{return wi<b.wi;}
} E[M+5];

struct edge
{
    int Next,to,wi;
    edge(const int Next_=0,const int to_=0,const int wi_=0):to(to_),wi(wi_),Next(Next_){}
} e[(N<<1)+5];

LL ans = 3e18,Tree_Weight;
int head[N+5],edge_tot,f[11][N+5],fw[11][N+5],fsw[11][N+5];

inline void add_edge(const int u,const int v,const int wi)
{
    e[++edge_tot] = edge(head[u],v,wi);
    head[u] = edge_tot;
    e[++edge_tot] = edge(head[v],u,wi);
    head[v] = edge_tot;
}

int UnionFind[N+5],Size[N+5],n,m,deep[N+5];

inline int Min(const int x,const int y){return x < y ? x : y;}
inline int Max(const int x,const int y){return x < y ? y : x;}
inline LL Min(const LL x,const int y){return x < y ? x : y;}

inline int Find(const int x){return (x == UnionFind[x]) ? x : (UnionFind[x] = Find(UnionFind[x]));}

inline void Unity(int x,int y)
{
    x = Find(x);y = Find(y);
    if(x == y) return;
    if(Size[x] > Size[y]) x^=y^=x^=y;
    UnionFind[y] = x;
    Size[x] += Size[y];
}

void dfs(const int u)
{
    for(reg int i = 1; i <= Max_Step ; ++i) f[i][u] = f[i-1][f[i-1][u]];
    for(reg int i = 1; i <= Max_Step ; ++i) fw[i][u] = Max(fw[i-1][u],fw[i-1][f[i-1][u]]);
    for(reg int i = 1; i <= Max_Step ; ++i)
        if(fw[i-1][u] == fw[i-1][f[i-1][u]]) fsw[i][u] = Max(fsw[i-1][u],fsw[i-1][f[i-1][u]]);
        else fsw[i][u] = Max(Min(fw[i-1][u],fw[i-1][f[i-1][u]]),Max(fsw[i-1][u],fsw[i-1][f[i-1][u]]));

    for(reg int i = head[u]; i ; i = e[i].Next)
        if(e[i].to != f[0][u])
        {
            deep[e[i].to] = deep[u] + 1;
            fw[0][e[i].to] = e[i].wi;
            fsw[0][e[i].to] = -1;
            f[0][e[i].to] = u;
            dfs(e[i].to);
        }
}

inline int LCA(int x,int y)
{
    if(deep[x] < deep[y]) x^=y^=x^=y;
    int deth = deep[x]-deep[y];
    for(reg int i = 0; i <= Max_Step ; ++i) if(deth&(1<<i)) x = f[i][x];
    if(x == y) return x;
    for(reg int i = Max_Step; i >= 0 ; --i) if(f[i][x] != f[i][y]){x = f[i][x];y = f[i][y];}
    return f[0][x];
}

inline void Pretreatment()
{
    n  = Read();m = Read();

    for(reg int i = 1; i <= m ; ++i) E[i] = EDGE(Read(),Read(),Read());

    for(reg int i = 1; i <= n ; ++i) Size[i] = 1;

    for(reg int i = 1; i <= n ; ++i) UnionFind[i] = i;

    std::sort(E+1,E+m+1);

    for(reg int i = 1; i <= m ; ++i)
        if(Find(E[i].u) != Find(E[i].v))
        {
            E[i].Used = true;
            add_edge(E[i].u,E[i].v,E[i].wi);
            Unity(E[i].u,E[i].v);
            Tree_Weight += E[i].wi;
        }

    f[0][0] = 1;
    dfs(1);
}

inline void Work(const int S,const int T,const int D_W)
{
    int mw = 0,msw = 0,deth = deep[S] - deep[T];
    for(reg int i = 0; i <= Max_Step ; ++i)
        if(deth & (1<<i))
        {
            msw = Max(msw,fsw[i][S]);
            if(fw[i][S] > mw){msw = Max(mw,msw);mw = fw[i][S];}
        }
    if(mw == D_W) ans = Min(ans,D_W-msw);
    else ans = Min(ans,D_W-mw);
}

inline void Solve()
{
    for(reg int i = 1; i <= m ; ++i)
        if(!E[i].Used)
        {
            int lca = LCA(E[i].u,E[i].v);
            Work(E[i].u,lca,E[i].wi);
            Work(E[i].v,lca,E[i].wi);
        }
    printf("%lld",ans+Tree_Weight);
}

int main()
{
    Pretreatment();
    Solve();
    return 0;
}
