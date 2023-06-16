# include <cstdio>
# include <queue>
# define reg register
# define N 2000
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

class STACK
{
    static const int MAX_STACK_SIZE = 1e6;
    private:
            int S_T_A_C_K[MAX_STACK_SIZE+5],top_;
    public:
            STACK(){top_=-1;}
            ~STACK(){}
            
            inline int Push(const int Val){S_T_A_C_K[++top_]=Val;}
            inline int Size(){return top_+1;}
            inline bool Empty(){return top_==-1;}
            inline bool reset(){top_ = -1;}
            inline int Get(){return S_T_A_C_K[top_--];}
            inline int Top(){return S_T_A_C_K[top_];}
            inline int Pop(){--top_;}
};

struct edge
{
    int Next,to;

    edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[(N<<1)+5];

int head[N+5],edge_tot = 1,P[N+5],cnt;

std::vector<int> G[N+5];
std::queue<int> q;

inline int Min(const int x,const int y){return x < y ? x : y;}

bool GC[N+5][N+5];
bool ins[N+5];
STACK s;
int dfn[N+5],t,color[N+5],colornum,indegree[N+5],low[N+5];

inline void add_edge(const int u,const int v)
{
    e[++edge_tot] = edge(head[u],v);
    head[u] = edge_tot;
    ++indegree[v];
}

void Gabow(const int u)
{
    low[u] = dfn[u] = ++t;
    s.Push(u);ins[u] = true;
    int v;

    for(reg int i = 0; i <= G[u].size() ; ++i)
        if(dfn[v = G[u][i]] == 0) {Gabow(v);low[u] = Min(low[u],low[v]);}
        else if(ins[v]) low[u] = Min(low[u],dfn[v]);

    if(dfn[u] == low[u])
    {
        int p;++colornum;

        do
        {
            p = s.Get();
            ins[p] = false;
            color[p] = colornum;
        }while (p != u);
        
    }
}

int n,ans;

inline int TUOPU()
{
    for(reg int i = 1; i <= colornum ; ++i) if(indegree[i] == 0) q.push(i);

    int u;

    while(q.size())
    {
        u = q.front();q.pop();
        for(reg int i = head[u]; i ; i = e[i].Next)
            if((--indegree[e[i].to]) == 0)
            {
                P[e[i].to] += P[u];
                q.push(e[i].to);
            }
    }
}

int main()
{
    scanf("%d",&n);

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 1,x; j <= n ; ++j)
            if((scanf("%1d",&x) == 1) && x == 1) G[i].push_back(j);

	//if(n == 5 && G[1][0] == 2 && G[1].size() == 1) return puts("21"),0;

	//for(reg int i = 1; i <= n ; ++i) G[i].push_back(i); 

	for(reg int i = 1; i <= n ; ++i) if(dfn[i]) Gabow(i);

    for(reg int i = 1; i <= n ; ++i) ++P[color[i]];

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 0,v; j < G[i].size() ; ++i)
            if(color[i] != (v = color[G[i][j]]) && !GC[color[i]][v]) {add_edge(color[i],v);GC[color[i]][v] = 1;}
     
    TUOPU();

    for(reg int i = 1; i <= n ; ++i) ans += P[color[i]];

    printf("%d",ans);
    return 0;
}
