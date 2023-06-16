# include <queue>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 1000
inline int Read()
{
    register int x = 0,f = 1;char ch = getchar();

    while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return f < 0 ? ~x+1 : x;
}

struct edge
{
    int Next,to,wi;

    edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<10) + 42];
int head[N + 42],edge_tot = 1,n,ml,md;

inline void add_edge(const int u,const int v,const int wi)
{
    e[++edge_tot] = edge(head[u],v,wi);

    head[u] = edge_tot;

    /*e[++edge_tot] = edge(head[v],u,wi);

    head[v] = edge_tot;*/
}

bool inq[N+5];
std::queue<int> q;
int qn[N+5],dis[N+5];

bool SPFA(const int S=n+1)
{
	memset(inq,0,sizeof(inq));
    memset(qn,0,sizeof(qn));
    memset(dis,0x3f,sizeof(dis));
    dis[S] = 0;inq[S] = true;q.push(S);
    register int u;

    while(q.size())
    {
        u = q.front();q.pop();
        inq[u] = 0;
        if((++qn[u]) > n) return false;

        for(reg int i = head[u]; i ; i = e[i].Next)
            if(dis[u]+e[i].wi < dis[e[i].to])
            {
                dis[e[i].to] = dis[u]+e[i].wi;
                if(!inq[e[i].to]){inq[e[i].to] = 1;q.push(e[i].to);}
            }
    }

    return true;
}

int main()
{
    n = Read();ml = Read();md = Read();

    for(reg int i = 1,x,y; i <= ml ; ++i)
    {
        x = Read();y = Read();
        add_edge(x,y,Read());
    }

    for(reg int i = 1,x,y; i <= md ; ++i)
    {
        x = Read();y = Read();
        add_edge(y,x,-Read());
    }

    for(reg int i = 1; i <= n ; ++i) add_edge(n+1,i,0);

    if(SPFA(n+1))
    {
        SPFA(1);
        if(0x3f3f3f3f == dis[n]) printf("-2");
        else printf("%d",dis[n]);
    }
    else printf("-1");

    return 0;
}
