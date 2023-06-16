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
# define N 10000
# define M 100000
# define reg //register
using std::map;
using std::cin;
using std::cout;
using std::string;

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

int n,m,edge_tot = 1,S,T,head[N+5],ans;

inline void add_edge(const int u,const int v,const int wi,const int Flow)
{
    e[++edge_tot] = edge(head[u],v,wi,Flow);
    head[u] = edge_tot;
}

string s1,s2;
bool inq[N+5];
map<string,int> mp;
int dis[N+5],flow[N+5],Pre[N+5];

void Input()
{
    cin>>n>>m;

    for(reg int i = 1; i <= n ; ++i)
    {
        cin>>s1;
        mp[s1] = i;
    }
}

void Build_Graph()
{
    Input();
    S = 1;T = n;
    add_edge(S,S+n,0,2);add_edge(S+n,1,0,0);
    add_edge(T,T+n,0,2);add_edge(T+n,T,0,0);

    for(reg int i = 2; i < n ; ++i){add_edge(i,i+n,0,1);add_edge(i+n,i,0,0);}

    for(reg int i = 1,x,y; i <= m ; ++i)
    {
        cin>>s1>>s2;
        x = mp[s1];y = mp[s2];
        if(y < x) x ^= y ^= x ^= y;
        add_edge(x+n,y,1,1);
        add_edge(y,x+n,-1,0);
    }
}

bool SPFA()
{
    memset(inq,0,sizeof(inq));
    memset(dis,-1,sizeof(dis));
    memset(flow,0x3f,sizeof(flow));
    q.reset();q.Push(S);inq[S] = 1;dis[S] = 0;
    
    while(q.Size())
    {
        int u = q.Get();inq[u] = 0;
        
        for(reg int i = head[u]; i ; i = e[i].Next)
            if(e[i].Flow > 0 && (dis[e[i].to] < dis[u] + e[i].Wi))
            {
                dis[e[i].to] = dis[u] + e[i].Wi;
                Pre[e[i].to] = i;
                flow[e[i].to] = flow[u] > e[i].Flow ? e[i].Flow : flow[u];
                if(!inq[e[i].to]){q.Push(e[i].to);inq[e[i].to] = 1;}
            }
    }

    return dis[T] != -1;
}

inline bool MCMF()
{
    int Max_Flow = 0;

    while(SPFA())
    {
        Max_Flow += flow[T];
        ans += flow[T] * dis[T];
        reg int u = T;
        
		while (u != S)
        {
            e[Pre[u]].Flow -= flow[T];
            
			e[Pre[u]^1].Flow += flow[T];
		
            u = e[Pre[u]^1].to;
        }
    }

    return Max_Flow == 2;
}

int main()
{
	//freopen("tour9.in","r",stdin);
    Build_Graph();

    if(MCMF()) printf("%d",ans);
    else printf("1");

    return 0;
}
