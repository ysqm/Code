# include <queue>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 300000
# define LL long long
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
using std::priority_queue;
char BB[1<<15],*SS=BB,*TT=BB;
inline int Read()
{
    register int x = 0;char ch = Gc;

    while(ch < '0' || ch > '9')ch = Gc;

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

    return x;
}
struct edge
{
    int Next,to,wi,idx;

    edge(const int Next_=0,const int To_=0,const int wi_=0,const int id=0):Next(Next_),to(To_),wi(wi_),idx(id){}
} e[(N<<1) + 42];

struct node
{
    int to,idx;
    LL wi;
    
    node(const int to_=0,const LL wi_=0,const int id=0):to(to_),wi(wi_),idx(id){}
    
    inline bool operator < (const node& b)const {return wi > b.wi;}
};

priority_queue<node> q;
int head[N + 42],edge_tot,n,m,k,sta=1,ans[N+5],top;
LL dis[N+5];

inline void add_edge(const int wi,const int v,const int u,const int id)
{
    e[++edge_tot] = edge(head[u],v,wi,id);

    head[u] = edge_tot;

    e[++edge_tot] = edge(head[v],u,wi,id);

    head[v] = edge_tot;
}

inline void Dijstra(const int S=1)
{
    memset(dis,0x3f,sizeof(dis));
    dis[S] = 0;

    for(reg int i = head[S]; i ; i = e[i].Next)
            if(dis[e[i].to] == dis[0]) q.push(node(e[i].to,e[i].wi,e[i].idx));
    
    while(top < k && q.size())
    {
        node u = q.top();q.pop();
        while(dis[u.to] != dis[0] && q.size()) {u = q.top();q.pop();}
        if(dis[u.to] != dis[0] && q.empty()) return;
        dis[u.to] = u.wi;
        ans[++top] = u.idx;
        for(reg int i = head[u.to]; i ; i = e[i].Next)
            if(dis[e[i].to] == dis[0]) q.push(node(e[i].to,dis[u.to]+e[i].wi,e[i].idx));
    }
    return;
}

signed main()
{
    n = Read();m = Read();k = Read();

    for(reg int i = 1; i <= m ; ++i) add_edge(Read(),Read(),Read(),i);

    Dijstra();

    printf("%d\n",top);

    for(reg int i = 1; i <= top ; ++i) printf("%d ",ans[i]);

    return 0;
}
