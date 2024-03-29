# include <cstdio>
# include <cstring>
# include <queue> 
# define reg register
# define N 5000
inline int Read()
{
    register int x = 0,f = 1;char ch = getchar();

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return f < 0 ? ~x+1 : x;
}

inline int Min(const int x,const int y){return x < y ? x : y;}
inline int Max(const int x,const int y){return x > y ? x : y;}

struct edge
{
    int Next,to,wi;

    edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<1) + 42];
int head[N + 42],edge_tot = 1;

inline void add_edge(const int u,const int v,const int wi)
{
    e[++edge_tot] = edge(head[u],v,wi);

    head[u] = edge_tot;

    /*e[++edge_tot] = edge(head[v],u,wi);

    head[v] = edge_tot;*/
}

bool inq[N+5];
std::queue<int> q;
int qn[N+5],dis[N+5],n,m;

inline bool SPFA(const int S)
{
    memset(dis,0x3f,sizeof(dis));
    dis[S] = 0;q.push(S);
    reg int u;

    while(q.size())
    {
        u = q.front();q.pop();
        inq[u] = false;

        for(reg int i = head[u]; i ; i = e[i].Next)
            if(dis[u]+e[i].wi < dis[e[i].to])
            {
                dis[e[i].to] = dis[u]+e[i].wi;
                if(!inq[e[i].to]){q.push(e[i].to);inq[e[i].to] = true;}
                if(++qn[e[i].to] > n) return false;
            }
    }
    return true;
}

int main()
{
    n = Read();m = Read();

    for(reg int i = 1,x,y; i <= m ; ++i)
    {
        x = Read();y = Read();
        add_edge(y,x,Read());
    }

    for(reg int i = 1; i <= n ; ++i) add_edge(n+1,i,0);

    if(SPFA(n+1)) for(reg int i = 1; i <= n ; ++i) printf("%d ",dis[i]);
    else printf("NO"); 

    return 0;
}
