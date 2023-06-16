# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 200000
# define M 1000000
inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

class Queue
{
    static const int MAX_QUEUE_SIZE = 2e5;
    private:
            int Q_U_E_E[MAX_QUEUE_SIZE],rear_,front_;
    public:
            Queue(){rear_=-1;front_=0;}
            ~Queue(){}

            inline void Push(const int Val){Q_U_E_E[++rear_] = Val;}
            inline int Size(){return rear_-front_+1;}
            inline void reset(){rear_=-1;front_=0;}
            inline bool Empty(){return rear_ < front_;}
            inline int Get(){return Q_U_E_E[front_++];}
            inline int Front(){return Q_U_E_E[front_];}
            inline void Pop(){++front_;}
} q;

struct edge
{
    int Next,to,wi;

    edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[M+5];

int head[N+5],edge_tot,U[M+5],n;

inline void add_edge(const int wi,const int v,const int u)
{
    e[++edge_tot] = edge(head[u],v,wi);
    head[u] = edge_tot;
}

inline int Min(const int x,const int y){return x < y ? x : y;}
inline int Max(const int x,const int y){return x > y ? x : y;}

bool ins[N+5];
int idt,low[N+5],dfn[N+5],top,s[N+5],scn,scc[N+5],indegree[N+5],dis[N+5];

int Tarjan(const int u)
{
    low[u] = dfn[u] = ++idt;
    s[++top] = u;ins[u] = true;
    
    for(reg int i = head[u]; i ; i = e[i].Next)
        if(dfn[e[i].to] == 0)
        {
            Tarjan(e[i].to);
            low[u] = Min(low[e[i].to],low[u]);
        }
        else if(ins[e[i].to]) low[u] = Min(low[u],dfn[e[i].to]);
    
    if(dfn[u] == low[u])
    {
        int p;
        dis[++scn] = 0x3f3f3f3f;
        do
        {
            p = s[top--];
            ins[p] = false;
            scc[p] = scn;
        }while(p != u);
    }
}

void Input()
{
    int m;
    n = Read();m = Read();

    for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),U[edge_tot+1] = Read());
	
    edge_tot = 0;
    Tarjan(1);
    memset(head,0,sizeof(head));

    for(reg int i = 1; i <= m ; ++i)
		if(scc[e[i].to] != scc[U[i]]){++indegree[scc[e[i].to]];add_edge(e[i].wi,scc[e[i].to],scc[U[i]]);}
}

void Solve()
{
    q.Push(scc[1]);
    dis[scc[1]] = 0;
    for(reg int i = 1; i <= scn ; ++i) if(indegree[i] == 0) q.Push(i);
    while(q.Size())
    {
        int u = q.Get();

        for(reg int i = head[u]; i ; i = e[i].Next)
        {
            dis[e[i].to] = Min(dis[e[i].to],dis[u]+e[i].wi);
            if((--indegree[e[i].to]) == 0) q.Push(e[i].to);
        }
    }

    printf("%d",dis[scc[n]]);
}

int main()
{
	//freopen("P2169_3.in","r",stdin);
	
    Input();

    Solve();

    return 0;
}
