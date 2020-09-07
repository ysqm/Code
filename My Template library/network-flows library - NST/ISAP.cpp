# include <cstdio>
# include <cstring>
# define reg register
# define N 1200
# define M 240000
# define LL long long
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

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
    int Next,to,Flow;
    edge(const int Next_=0,const int to_=0,const int flow_=0):Next(Next_),to(to_),Flow(flow_){}
} e[(M<<1)+5];

int edge_tot=1,head[N+5];

void add_edge(const int wi,const int v,const int u)
{
    e[++edge_tot] = edge(head[u],v,wi);
    head[u] = edge_tot;
    e[++edge_tot] = edge(head[v],u,0);
    head[v] = edge_tot;
}

inline int Min(const int x,const int y){return x < y ? x : y;}

int high[N+5],gap[N+5],nowedge[N+5],S,T,n;

void BFS()
{
    memset(high,-1,sizeof(high));
    memset(gap,0,sizeof(gap));
    high[T] = 0;gap[0] = 1;
    q.reset();q.Push(T);
    int u,v,uhi;

    while(q.Size())
    {
        uhi = high[u = q.Get()]+1;
        for(reg int i = head[u]; i ; i = e[i].Next)
            if(high[v = e[i].to] == -1)
            {
                q.Push(v);
                ++gap[high[v] = uhi];
            }
    }
}

long long Max_Flow;

int ISAP_DFS(const int u,const LL Flow)
{
    if(u == T)
	{
		Max_Flow += Flow;
		return Flow;
	}
    else
    {
        int trueflow = 0;
		int Feasible_flow = 0;
        for(reg int i = nowedge[u]; i ; i = e[i].Next)
            {
                nowedge[u] = i;
                if(e[i].Flow && high[e[i].to]+1 == high[u])
                {
                    Feasible_flow = ISAP_DFS(e[i].to,Min(e[i].Flow,Flow-trueflow));
                    if(Feasible_flow)
                    {
                        e[i].Flow -= Feasible_flow;
                        e[i^1].Flow += Feasible_flow;
                        trueflow += Feasible_flow;
                    }
                    if(trueflow == Flow) return Flow;
                }
            }
        if(--gap[high[u]++] == 0) high[S] = n+1;
        ++gap[high[u]];
        return trueflow;
    }
}

long long ISAP()
{
    Max_Flow = 0;BFS();

    while(high[S] < n){memcpy(nowedge,head,sizeof(head));ISAP_DFS(S,0x7f7f7f7f7f7f7f7f);}
    
    return Max_Flow;
}

int main()
{
    int m;

    n = Read();m = Read();S = Read();T = Read();

    for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),Read());
    
    printf("%lld",ISAP());

    return 0;
}
