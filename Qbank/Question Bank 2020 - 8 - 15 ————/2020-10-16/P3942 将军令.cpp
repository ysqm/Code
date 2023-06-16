# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <iostream>
# include <algorithm>
# define LL long long
# define N 100000
inline int Read()
{
    register int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9')ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}

    return x;
}

struct edge
{
    int Next,to;
    edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
} e[(N<<1)+5];

int head[N+5],edge_tot,deep[N+5],fa[N+5];
bool vis[N+5];

inline void add_edge(const int u,const int v)
{
    e[++edge_tot] = edge(head[u],v);
    head[u] = edge_tot;
    e[++edge_tot] = edge(head[v],u);
    head[v] = edge_tot;
}

struct node
{
    int u,dep;
    node(const int u_=0,const int dep_=0):u(u_),dep(dep_){}
    bool operator < (const node& b)const{return dep < b.dep;}
};

std::priority_queue<node> q;

void dfs(const int u)
{
    for(int i = head[u]; i ; i = e[i].Next)
        if(deep[e[i].to] == 0)
        {
            fa[e[i].to] = u;
            deep[e[i].to] = deep[u] + 1;
            dfs(e[i].to);
        }
}

int Get_father(int u,int x)
{
    int k = 1;
    while(k <= x){++k;u = fa[u];}
    return u;
}

void Modify(const int u,const int lst,const int k)
{
    vis[u] = 1;
    if(k)
		for(int i = head[u]; i ; i = e[i].Next)
        	if(e[i].to != lst) Modify(e[i].to,u,k-1);
}

int n,k,t;

void Solve()
{
    fa[1] = 1;deep[1] = 1;
    dfs(1);
    for(int i = 1; i <= n ; ++i) q.push(node(i,deep[i]));
    int ans = 0;
    do
    {
        int u = q.top().u;q.pop();
        if(vis[u]) continue;
        u = Get_father(u,k);
        Modify(u,u,k);++ans;
    }while(q.size());
    printf("%d\n",ans);
}

int main()
{
    n = Read();k = Read();t = Read();
    for(int i = 2; i <= n ; ++i) add_edge(Read(),Read());
    Solve();
    return 0;
}