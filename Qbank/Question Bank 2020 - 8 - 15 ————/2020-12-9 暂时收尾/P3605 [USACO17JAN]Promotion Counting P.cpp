# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define LL long long
# define FileRead(x) freopen(#x".in","r",stdin)
# define FileWrite(x) freopen(#x".out","w",stdout) 
namespace IO
{
    char BB[1<<15],*SS=BB,*TT=BB;
    inline char Gc(){return (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++);}
    inline bool Isdigit(const char ch){return '0' <= ch && ch <= '9';}
    inline int Read()
    {
        register int x = 0;char ch = Gc();
    
        while(!Isdigit(ch)) ch = Gc();
    
        while(Isdigit(ch)){x = x*10+(ch^48);ch = Gc();}
    
        return x;
    }
    
    inline int Max(const int x,const int y){return x < y ? y : x;}
    inline int Min(const int x,const int y){return x < y ? x : y;}
}

namespace Solution
{
    const int N = 1e5;
    
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
    }
    
    int a[N+5],p[N+5],n,tr[N+5],ans[N+5];
    
    void Insert(int x,const int data){for(; x <= n ; x += (x&(-x))) tr[x] += data;}
    
    int Q(int x){int res = 0;for(; x ; x -= (x&(-x))) res += tr[x];return res;}
    
    void dfs(const int u)
    {
        ans[u] -= Q(p[u]);
        for(int i = head[u]; i ; i = e[i].Next) dfs(e[i].to);
        ans[u] += Q(p[u]);
        Insert(p[u],1);
    }
    
    
    int Solve()
    {
        FileRead(ysqm);
        n = IO::Read();
        for(int i = 1; i <= n ; ++i) a[i] = p[i] = IO::Read();
        std::sort(a+1,a+n+1);
        for(int i = 1; i <= n ; ++i) p[i] = n-(std::lower_bound(a+1,a+1+n,p[i])-a)+1;
        //for(int i = 1; i <= n ; ++i)
        for(int i = 2; i <= n ; ++i) add_edge(IO::Read(),i);
        dfs(1);
        for(int i = 1; i <= n ; ++i) printf("%d\n",ans[i]);
        return 0;
    }
}

int main(){return Solution::Solve();}
