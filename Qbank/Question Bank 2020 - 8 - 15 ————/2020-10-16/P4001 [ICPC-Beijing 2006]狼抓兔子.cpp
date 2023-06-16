# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <iostream>
# define N 1000000
# define LL long long
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
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
    static const int MAX_QUEUE_SIZE = 1e6;
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
    int Next,to,cf;

    edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),cf(wi_){}
} e[N*6+5];

int head[N+5],edge_tot = 1;

inline void add_edge(const int u,const int v,const int wi)
{
    e[++edge_tot] = edge(head[u],v,wi);
    head[u] = edge_tot;
    e[++edge_tot] = edge(head[v],u,wi);
    head[v] = edge_tot;
}

int high[N+5],gap[N+5],nowedge[N+5],GraphSize,S,T;

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
        for(int i = head[u]; i ; i = e[i].Next)
            if(high[v = e[i].to] == -1)
            {
                q.Push(v);
                ++gap[high[v] = uhi];
            }
    }
}

inline int Min(const int x,const int y){return x < y ? x : y;}

int ISAP_DFS(const int u,const int flow)
{
    if(u == T) return flow;
    int Feasible_Flow,True_Flow = 0;
    for(int &i = nowedge[u]; i ; i = e[i].Next)
        if(e[i].cf && high[e[i].to]+1 == high[u])
        {
            Feasible_Flow = ISAP_DFS(e[i].to,Min(e[i].cf,flow-True_Flow));
            if(Feasible_Flow)
            {
                e[i].cf -= Feasible_Flow;
                e[i^1].cf += Feasible_Flow;
                if((True_Flow += Feasible_Flow) == flow) return flow;
            }
        }
    if((--gap[high[u]++]) == 0) high[S] = GraphSize+1;
    ++gap[high[u]];
    return True_Flow;
}

int ISAP()
{
    int Max_Flow = 0;BFS();
    while(high[S] < GraphSize)
	{
		for(int i = 1; i <= GraphSize ; ++i) nowedge[i] = head[i];
		Max_Flow += ISAP_DFS(S,0x7f7f7f7f);
	}
    return Max_Flow;
}

int n,m;

int Calc(const int x,const int y){return (x-1)*m + y;}

void Build()
{
    n = Read();m = Read();
    for(int i = 1; i <= n ; ++i)
        for(int j = 1; j < m ; ++j)
            add_edge(Calc(i,j),Calc(i,j+1),Read());
    for(int i = 1; i < n ; ++i)
        for(int j = 1; j <= m ; ++j)
            add_edge(Calc(i,j),Calc(i+1,j),Read());
    for(int i = 1; i < n ; ++i)
        for(int j = 1; j < m ; ++j)
            add_edge(Calc(i,j),Calc(i+1,j+1),Read());
    GraphSize = n*m;
    S = Calc(1,1);
    T = Calc(n,m);
}

int main()
{
    freopen("ysqm.in","r",stdin);
    Build();
    printf("%d",ISAP());
    return 0;
}
