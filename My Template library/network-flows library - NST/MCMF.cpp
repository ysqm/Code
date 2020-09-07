# include <map>
# include <queue>
# include <ctime>
# include <cmath>
# include <vector>
# include <cstdio>
# include <string>
# include <cstdlib>
# include <cstring>
# include <iostream>
# include <algorithm>
# define N 5000
# define M 100000
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
    int Next,to,Wi,Flow;
    edge(const int Next_=0,const int to_=0,const int Wi_=0,const int Flow_=0):Next(Next_),to(to_),Wi(Wi_),Flow(Flow_){}
} e[M+5];

int n,m,edge_tot = 1,S,T,head[N+5];

inline void add_edge(const int u,const int v,const int wi,const int Flow)
{
    e[++edge_tot] = edge(head[u],v,wi,Flow);
    head[u] = edge_tot;
}

bool inq[N+5];
int dis[N+5],flow[N+5],Pre[N+5];

void Build_Graph()
{
    n = Read();m = Read();S = Read();T = Read();
    
    for(reg int i = 1,u,v,w,f; i <= m ; ++i)
    {
        u = Read();v = Read();w = Read();f = Read();
        add_edge(u,v,f,w);
        add_edge(v,u,-f,0);
    }
}

bool SPFA()
{
    memset(inq,0,sizeof(inq));
    memset(dis,0x3f,sizeof(dis));
    memset(flow,0x3f,sizeof(flow));
	q.reset();q.Push(S);inq[S] = 1;dis[S] = 0;
    
    while(q.Size())
    {
        int u = q.Get();inq[u] = 0;
        
        for(reg int i = head[u]; i ; i = e[i].Next)
            if(dis[e[i].to] > dis[u] + e[i].Wi && e[i].Flow > 0)
            {
                dis[e[i].to] = dis[u] + e[i].Wi;
                Pre[e[i].to] = i;
                flow[e[i].to] = flow[u] > e[i].Flow ? e[i].Flow : flow[u];
                if(!inq[e[i].to]){q.Push(e[i].to);inq[e[i].to] = 1;}
            }
    }

    return dis[T] < dis[0];
}

void MCMF()
{
    int Max_Flow = 0,Min_Cost = 0;

    while(SPFA())
    {
        Max_Flow += flow[T];
        Min_Cost += flow[T] * dis[T];
        reg int u = T;
        
		while (u != S)
        {
            e[Pre[u]].Flow -= flow[T];
            
			e[Pre[u]^1].Flow += flow[T];
		
            u = e[Pre[u]^1].to;
        }
    }

    printf("%d %d",Max_Flow,Min_Cost);
    return;
}

int main()
{
	freopen("P3381_8.in","r",stdin);

    Build_Graph();

    MCMF();

    return 0;
}
