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
    
    int head[N+5],edge_tot,c[N+5],n,cnt[N+5];
    
    inline void add_edge(const int u,const int v)
    {
        e[++edge_tot] = edge(head[u],v);
    
        head[u] = edge_tot;
    
        e[++edge_tot] = edge(head[v],u);
    
        head[v] = edge_tot;
    }
    
    int Son[N+5],Size[N+5],cntcol,fa[N+5];
    LL ans[N+5],sum;
    
    void dfs1(const int u)
    {
        Size[u] = 1;
        for(int i = head[u]; i ; i = e[i].Next)
            if(e[i].to != fa[u])
            {
                fa[e[i].to] = u;
                dfs1(e[i].to);
                Size[u] += Size[e[i].to];
                if(Size[e[i].to] > Size[Son[u]]) Son[u] = e[i].to; 
            }
    }
    
    void Clear(const int u)
    {
        --cnt[c[u]];
        for(int i = head[u]; i ; i = e[i].Next) if(fa[u] != e[i].to) Clear(e[i].to);
    }
    
    void Calc(const int u,const int p)
    {
        ++cnt[c[u]];
        if(cnt[c[u]] > cntcol) {cntcol = cnt[c[u]];sum = c[u];}
        else if(cnt[c[u]] == cntcol) sum += c[u];
        for(int i = head[u]; i ; i = e[i].Next) if(e[i].to != p && e[i].to != fa[u]) Calc(e[i].to,p);
    }
    
    void DSU(const int u)
    {
        ans[u] = 0;
        for(int i = head[u]; i ; i = e[i].Next)
            if(e[i].to != Son[u] && e[i].to != fa[u])
            {
                DSU(e[i].to);
                Clear(e[i].to);
                sum = 0;cntcol = 0; 
            }
        if(Son[u]) DSU(Son[u]);
        Calc(u,Son[u]);
        ans[u] = sum;
    }
    
    int Solve()
    {
        FileRead(ysqm);
        n = IO::Read();
        for(int i = 1; i <= n ; ++i) c[i] = IO::Read();
        for(int i = 2; i <= n ; ++i) add_edge(IO::Read(),IO::Read());
        dfs1(1);
        DSU(1);
        for(int i = 1; i <= n ; ++i) printf("%lld ",ans[i]);
    }
}

int main(){return Solution::Solve();}
