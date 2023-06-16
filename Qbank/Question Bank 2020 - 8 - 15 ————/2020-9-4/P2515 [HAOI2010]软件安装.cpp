# include <ctime>
# include <cmath>
# include <vector>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 100
# define M 500
# define reg register
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}

inline int Min(const int x,const int y){return x < y ? x : y;}

bool ins[N+5];
std::vector<int> G[N+5];
int n,m,OV[N+5],OW[N+5],idt,scc[N+5],scn,low[N+5],sh,s[N+5],dfn[N+5],W[N+5],V[N+5];

struct edge
{
    int Next,to;

    edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[(N<<1) + 42];

int head[N + 42],edge_tot,indegree[N+5],father[N+5],Size[N+5],dp[N+5][M+5],S;

inline void add_edge(const int u,const int v)
{
    e[++edge_tot] = edge(head[u],v);

    head[u] = edge_tot;

    ++indegree[v];
}

inline int Find_(const int x){return x == father[x] ? x : father[x] = Find_(father[x]);}
inline void UnionFindPretreatment(){for(reg int i = 1; i <= n ; ++i) Size[i] = 1,father[i] = i;}
inline void Unity(int x,int y)
{
    x = Find_(x);y = Find_(y);
    if(x == y) return ;
    if(Size[x] < Size[y]) x^=y^=x^=y;
    Size[x] += Size[y];father[y] = x;
}

void Tarjan(const int u)
{
    s[++sh] = u;ins[u] = true;
    dfn[u] = low[u] = ++idt;

    for(reg int i = 0,v; i < G[u].size(); ++i)
        if(dfn[v = G[u][i]] == 0)
        {
            Tarjan(v);
            low[u] = Min(low[v],low[u]);
        }
        else if(ins[v]) low[u] = Min(low[u],dfn[v]);

    if(dfn[u] == low[u])
    {
        int p;++scn;
        do
        {
            p = s[sh--];
            W[scn] += OV[p];
            V[scn] += OW[p];
            ins[p] = false;
            scc[p] = scn;
        }while(p != u);
    }
}

inline int Max(const int x,const int y){return x < y ? y : x;}

void dfs(const int u)
{
	for(reg int i = m; i >= V[u] ; --i) 
		dp[u][i] = Max(dp[u][i-V[u]]+W[u],dp[u][i]);
    for(reg int i = head[u]; i ; i = e[i].Next)
    {
        dfs(e[i].to);
        
		for(reg int k = m-V[u]; k >= 0 ; --k)
            for(reg int j = k; j >= 0 ; --j)
                dp[u][k+V[u]] = Max(dp[u][k+V[u]],dp[e[i].to][j]+dp[u][k-j+V[u]]);
    }
}

int main()
{
    n = Read();m = Read();

    for(reg int i = 1; i <= n ; ++i) *(OW+i) = Read();
    for(reg int i = 1; i <= n ; ++i) *(OV+i) = Read();
    for(reg int i = 1; i <= n ; ++i) G[Read()].push_back(i);
    
    for(reg int i = 1; i <= n ; ++i) if(dfn[i] == 0) Tarjan(i);

	UnionFindPretreatment();

    for(reg int i = 1; i <= n ; ++i)
    	for(reg int j = 0,v; j < G[i].size() ; ++j)
            if(Find_(scc[i]) != Find_(v = scc[G[i][j]]))
            {
                Unity(scc[i],v);
                add_edge(scc[i],v);
            }
    
    S = scn+1;W[S] = V[S] = 0;

    for(reg int i = 1; i <= n ; ++i) if(indegree[scc[i]] == 0) add_edge(S,scc[i]);

    dfs(S);

	printf("%d",dp[S][m]);

    return 0;
}