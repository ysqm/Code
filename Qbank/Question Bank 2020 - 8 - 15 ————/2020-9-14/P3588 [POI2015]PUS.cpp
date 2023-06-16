# include <queue>
# include <cstring>
# include <cstdio>
# define reg register
# define N 400000
# define Ls(K) (K<<1)
# define Rs(K) (K<<1|1)
# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
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
    int Next,to,wi;

    edge(const int Next_=0,const int To_=0,const int wi_=0):Next(Next_),to(To_),wi(wi_){}
} e[(N<<3)+5];

int head[(N<<3)+5],edge_tot = -1,degree[(N<<3)+5],n;

inline void add_edge(const int u,const int v,const int wi=0)
{
    e[++edge_tot] = edge(head[u],v,wi);

    head[u] = edge_tot;
    
    ++degree[v];
}

int Seg[(N<<2)+5],tot,id[(N<<3)+5],O[(N<<3)+5],idx[N+5];

void Build(const int L,const int R,const int K)
{
    Seg[K] = ++tot;
    if(L == R) {add_edge(tot,L);idx[tot] = O[L];}
    else
    {
        int mid = (L+R)>>1;
        Build(L,mid,Ls(K));
        Build(mid+1,R,Rs(K));
        add_edge(Seg[K],Seg[Ls(K)]);
        add_edge(Seg[K],Seg[Rs(K)]);
    }
}

void Modify(const int AL,const int AR,const int idx,const int L,const int R,const int K)
{
    if(AL <= L && R <= AR) add_edge(idx,Seg[K]);
    else
    {
        int mid = (L+R)>>1;
        if(AL <= mid) Modify(AL,AR,idx,L,mid,Ls(K));
        if(mid < AR) Modify(AL,AR,idx,mid+1,R,Rs(K));
    }
}

void Build_Graph()
{
    int m,s;
    n = Read();s = Read();m = Read();
    memset(head,-1,sizeof(head));
    tot = n;
    for(int i = 1,x; i <= s ; ++i)
    {
        x = Read();
        O[x] = Read();
    }
    Build(1,n,1);
    for(int i = 1,l,r,nk; i <= m ; ++i)
    {
        l = Read();r = Read();nk = Read();
        int Pre = l,x;++tot;
        for(int k = 1; k <= nk ; ++k)
        {
            x = Read();
            add_edge(x,tot,1);
            if(x > Pre) Modify(Pre,x-1,tot,1,n,1);
            Pre = x+1;
        }
        if(x < r) Modify(x+1,r,tot,1,n,1);
    }
    for(int i = 1; i <= tot ; ++i) if(idx[i] == 0) idx[i] = 1e9;
}

inline int Min(const int x,const int y){return x < y ? x : y;}

std::queue<int> q;

bool Solve()
{
    Build_Graph();
    int cnt = 0;
    for(int i = 1; i <= tot ; ++i) if(degree[i] == 0) q.push(i);
    while(q.size())
    {
        int u = q.front();q.pop();++cnt;
        for(int i = head[u]; ~i ; i = e[i].Next)
        {
            idx[e[i].to] = Min(idx[e[i].to],idx[u]-e[i].wi);
            if(O[e[i].to] > idx[e[i].to]) return false;
            if((--degree[e[i].to]) == 0) q.push(e[i].to);
        }
    }
    return cnt == tot;
}

int main()
{
    if(Solve())
    {
        puts("TAK");
        for(int i = 1; i <= n ; ++i)
            if(O[i]) printf("%d ",O[i]);
            else printf("%d ",idx[i]);
    }
    else puts("NIE");
    return 0;
}