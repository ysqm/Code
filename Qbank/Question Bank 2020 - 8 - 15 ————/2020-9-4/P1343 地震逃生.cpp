# include <cstdio>
# define N 200
# define M 2000
# define reg register
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

int Min(const int x,const int y){return x < y ? x : y;}

struct edge
{
    int Next,to,Flow;
    edge(const int Next_=0,const int v=0,const int Flow_=0):Next(Next_),to(v),Flow(Flow_){}
} e[(M<<1)+5];

int head[N+5],edge_tot=1,nowedge[N+5];

void add_edge(const int wi,const int v,const int u)
{
    e[++edge_tot] = edge(head[u],v,wi);
    head[u] = edge_tot;
    e[++edge_tot] = edge(head[v],u,0);
    head[v] = edge_tot;
}

int high[N+5],gap[N+5],GraphSize,S,T;

void BFS()
{
    for(reg int i = 1; i <= GraphSize ; ++i) high[i] = -1;
    for(reg int i = 1; i <= GraphSize ; ++i) gap[i] = 0;
    q.Push(T);high[T] = 0;gap[0] = 1;
    int u,uhigh;

    while(q.Size())
    {
        u = q.Get();uhigh = high[u]+1;

        for(reg int i = head[u]; i ; i = e[i].Next)
            if(high[e[i].to] == -1)
            {
                ++gap[high[e[i].to] = uhigh];
                q.Push(e[i].to);
            }
    }
}

int dfs(const int u,const int Flow)
{
    if(u == T) return Flow;

    int true_flow=0,Feasible_flow;

    for(reg int i = nowedge[u]; i ; i = e[i].Next)
    {
        nowedge[u] = i;
        if(e[i].Flow && high[e[i].to]+1 == high[u])
        {
            Feasible_flow = dfs(e[i].to,Min(e[i].Flow,Flow-true_flow));
            e[i].Flow -= Feasible_flow;
            e[i^1].Flow += Feasible_flow;
            if((true_flow += Feasible_flow) == Flow) return Flow;
        }
    }
    
    if(--gap[high[u]++] == 0) high[S] = GraphSize+1;
    ++gap[high[u]];
    return true_flow;
}

int ISAP()
{
    int Max_Flow = 0;BFS();

    while(high[S] < GraphSize)
    {
        for(reg int i = 1; i <= GraphSize ; ++i) nowedge[i] = head[i];
        Max_Flow += dfs(S,0x7f7f7f7f);
    }

    return Max_Flow;
}

int STUENT,MF;

void Build_Graph()
{
    GraphSize = Read();int m = Read();STUENT = Read();S = 1;T = GraphSize;

    for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),Read());
}

int main()
{
    Build_Graph();

    MF = ISAP();
    
    if(MF == 0) printf("Orz Ni Jinan Saint Cow!");
    else printf("%d %d",MF,STUENT%MF == 0 ? STUENT/MF : STUENT/MF+1);

    return 0;
}
