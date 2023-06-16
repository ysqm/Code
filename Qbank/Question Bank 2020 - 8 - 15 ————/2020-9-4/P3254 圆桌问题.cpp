# include <cstdio>
# include <vector>
# define N 420
# define M 40920
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

struct Queue
{
    int queue[N+5],top,rear;
    Queue(const int top_=0,const int rear_=-1):top(top_),rear(rear_){}
    inline void Push(const int x){queue[++rear] = x;}
    inline int Get(){return queue[top--];}
    inline bool Size(){return rear > top;}
} q;

int Min(const int x,const int y){return x < y ? x : y;}

struct edge
{
    int Next,to,Flow;
    edge(const int Next_=-1,const int to_=0,const int Flow_=0):Next(Next_),to(to_),Flow(Flow_){}
} e[(M<<1)+5];

int head[N+5],edge_tot=-1;

inline void add_edge(const int u,const int v,const int wi)
{
    e[++edge_tot] = edge(head[u],v,wi);head[u] = edge_tot;
    e[++edge_tot] = edge(head[v],u,0);head[v] = edge_tot;
}

int h[N+5],g[N+5],Graphsize,S,T,cur[N+5];

void BFS()
{
    for(reg int i = 1; i <= Graphsize ; ++i) h[i] = -1;
    g[h[T] = 0] = 1;q.Push(T);int u,uh;
    while(q.Size())
    {
        u = q.Get();uh = h[u]+1;
        for(reg int i = head[u]; ~i ; i = e[i].Next)
            if(h[e[i].to] == -1){h[e[i].to] = uh;q.Push(e[i].to);}
    }
}

int DFS(const int u,const int Flow)
{
    if(u == T) return Flow;
    int true_flow = 0;
    for(reg int &i = cur[u]; ~i ; i = e[i].Next)
        if(e[i].Flow && h[e[i].to]+1 == h[u])
        {
            int FFlow = DFS(e[i].to,Min(Flow-true_flow,e[i].Flow));
            e[i].Flow -= FFlow;
            e[i^1].Flow += FFlow;
            if((true_flow += FFlow) == Flow) return Flow;
        }
    if(--g[h[u]++] == 0) h[S] = Graphsize+1;
    ++g[h[u]];
    return true_flow;
}

int ISAP()
{
    int Max_Flow = 0;BFS();
    while(h[S] < Graphsize) {for(reg int i = 1; i <= Graphsize ; ++i) cur[i] = head[i];Max_Flow += DFS(S,0x7f7f7f7f);}
    return Max_Flow;
}

int need_Flow,n,m;

void Build_Graph()
{
    //freopen("1.in","r",stdin);
    scanf("%d%d",&m,&n);Graphsize = T = (S = n+m+1)+1;
    for(reg int i = 1; i <= Graphsize ; ++i) head[i] = -1;
    for(reg int i = 1,x; i <= m ; ++i) 
    {
        need_Flow += (x = Read());
        add_edge(S,i,x);
    }
    for(reg int i = 1; i <= n ; ++i) add_edge(i+m,T,Read());
    for(reg int i = 1; i <= m ; ++i) for(reg int j = 1; j <= n ; ++j) add_edge(i,j+m,1);
    fclose(stdin);
}

std::vector<int> G[155];

void Solve()
{
    int Max_Flow = ISAP();
    if(Max_Flow < need_Flow) puts("0");
    else 
    {
        puts("1");
        for(reg int u = 1; u <= m; ++u)
            for(reg int i = head[u]; ~i ; i = e[i].Next)
                if(e[i].to != S && e[i].Flow == 0) G[u].push_back(e[i].to-m);
        for(reg int u = 1; u <= m; ++u)
        {
            for(reg int j = 0; j < G[u].size(); ++j)
                printf("%d ",G[u][j]);
            printf("\n");
        }
            
    }
}

int main()
{
    Build_Graph();
    Solve();
    return 0;
}