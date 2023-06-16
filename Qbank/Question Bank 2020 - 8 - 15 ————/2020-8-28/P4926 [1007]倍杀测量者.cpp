# include <queue>
# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg //register
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
    int Next,to;
    double wi;
    edge(const int Next_=0,const int To_=0,const double wi_=0.0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<10) + 42];

struct EDGE
{
    int o,a,b,k;
    EDGE(const int k_=0,const int B=0,const int A=0,const int O=0):o(O),a(A),b(B),k(k_){}
} inp[N+5];

int head[N+5],edge_tot = 1,n,s,t,C[N+5];

inline void add_edge(const int u,const int v,const double wi)
{
    e[++edge_tot] = edge(head[u],v,wi);

    head[u] = edge_tot;
}

int qn[N+5];
bool inq[N+5];
double dis[N+5];
std::queue<int> q;


inline bool check(const double T)
{
    memset(head,0,sizeof(head));
    edge_tot = 0;
    while(q.size()) q.pop();

    for(reg int i = 1; i <= n+1 ; ++i) inq[i] = 1; 
    for(reg int i = 1; i <= n+1 ; ++i) qn[i] = 0;
    for(reg int i = 1; i <= n+1 ; ++i) q.push(i); 
    for(reg int i = 1; i <= n+1 ; ++i) dis[i] = 1.0;
    

    for(reg int i = 1; i <= n ; ++i) 
		if(C[i])
		{
			add_edge(i,n+1,1.0/C[i]);
			add_edge(n+1,i,C[i]);
		}

    for(reg int i = 1; i <= s ; ++i)
        if(inp[i].o == 1) add_edge(inp[i].b,inp[i].a,inp[i].k-T);
        else add_edge(inp[i].b,inp[i].a,1.0/(inp[i].k+T));

    int u;

    while(q.size())
    {  
        u = q.front();
        if((++qn[u]) > n) return true;

        for(reg int i = head[u]; i ; i = e[i].Next)
            if(dis[e[i].to] < dis[u]*e[i].wi)
            {
                dis[e[i].to] = dis[u]*e[i].wi;
                if(!inq[e[i].to]){inq[e[i].to] = 1;q.push(e[i].to);}
            }
        
        q.pop();inq[u] = 0;
    }

    return false;
}

int main()
{
    n = Read();s = Read();t = Read();

    for(reg int i = 1; i <= s ; ++i) inp[i] = EDGE(Read(),Read(),Read(),Read());

    for(reg int i = 1,idx; i <= t ; ++i){idx = Read();C[idx] = Read();}

    reg double l = 0,r = 1e9,mid,ans=-1;

    while(r-l > 1e-5)
    {
        mid = (l+r)/2;
        check(mid) ? l = (ans = mid) : r = mid;
    }

    ans == -1 ? puts("-1") : printf("%.18lf",ans);

    return 0;
}
