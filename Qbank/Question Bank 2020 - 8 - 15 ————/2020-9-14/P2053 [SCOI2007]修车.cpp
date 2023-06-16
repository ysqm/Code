# include <cstdio>
# include <cstring>
# define reg register
# define N 1000
# define NM 10000
# define INF 0x3f3f3f3f

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
    int Next,to,Flow,Cost;
    edge(const int Next_=0,const int to_=0,const int Flow_=0,const int Cost_=0):Next(Next_),to(to_),Flow(Flow_),Cost(Cost_){}
} e[NM+5];

int head[N+5],edge_tot=-1;

void add_edge(const int u,const int v,const int Flow,const int Cost)
{
    e[++edge_tot] = edge(head[u],v,Flow,Cost);
    head[u] = edge_tot;
    e[++edge_tot] = edge(head[v],u,0,-Cost);
    head[v] = edge_tot;
}

bool inq[N+5];
int Flow[N+5],Pre[N+5],dis[N+5],GraphSize,S,T,V;

int SPFA()
{
    for(reg int i = 1; i <= GraphSize ; ++i) Flow[i] = INF;
    for(reg int i = 1; i <= GraphSize ; ++i) dis[i] = INF;
    for(reg int i = 1; i <= GraphSize ; ++i) inq[i] = 0;
    dis[S] = 0;q.reset();q.Push(S);inq[S] = 1;

    while(q.Size())
    {
        int u = q.Get();inq[u] = 0;

        for(reg int i = head[u]; ~i ; i = e[i].Next)
            if(e[i].Flow > 0 && dis[e[i].to] > dis[u] + e[i].Cost)
            {
                dis[e[i].to] = dis[u] + e[i].Cost;
                Pre[e[i].to] = i;
                Flow[e[i].to] = Flow[e[i].to] > e[i].Flow ? e[i].Flow : Flow[e[i].to];
                if(!inq[e[i].to]){inq[e[i].to] = 1;q.Push(e[i].to);}
            }
    }

    return dis[T] < INF;
}

inline void Update()
{
    reg int u = T;

    while(u != S)
    {
        e[Pre[u]].Flow -= Flow[T];
        e[Pre[u]^1].Flow += Flow[T];
        u = e[Pre[u]^1].to;
    }
}

int MCMF()
{
    int Max_Flow=0,Min_Cost=0;

    while(SPFA())
    {
        Max_Flow += Flow[T];
        Min_Cost += dis[T]*Flow[T];
        Update();
    }

    return Min_Cost;
}

int Build_Graph()
{
    int n,m,x;

    scanf("%d%d",&m,&n);

    memset(head,-1,sizeof(head));

    GraphSize = T = (S = (V = n*m) + n + 1) + 1;

    for(reg int i = 1; i <= n ; ++i)
        for(reg int j = 1; j <= m ; ++j)
        {
            scanf("%d",&x);
            for(reg int k = 1; k <= n ; ++k) add_edge(V+i,(j - 1)*n + k,1,k*x);
        }

    for(reg int i = 1; i <= n ; ++i) add_edge(S,V+i,1,0);
    for(reg int i = 1; i <= V ; ++i) add_edge(i,T,1,0);

    return n;
}

int main()
{
    int n = Build_Graph();
    int Min_Flow = MCMF();
    printf("%lf",Min_Flow*1.0/n);
    return 0;
}
