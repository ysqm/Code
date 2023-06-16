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
    //inline char Gc(){return (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++);}
    # define Gc() getchar()
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

# define N 100000

bool vis[N+5];
int lc[N+5],rc[N+5],v[N+5],dis[N+5],n,m,rt[N+5],fa[N+5],tot;

int Create(const int Val)
{
    dis[++tot] = 0;
    lc[tot] = rc[tot] = 0;
    v[tot] = Val;
    //Size[tot] = 1;
    return fa[tot] = tot;
}

int Find(const int x){return fa[x] == x ? x : fa[x] = Find(fa[x]);}

int Merge(int x,int y)
{
    if(x == 0 || y == 0) return x+y;
    if(v[x] > v[y]) x ^= y ^= x ^= y;
    rc[x] = Merge(rc[x],y);
    if(dis[lc[x]] < dis[rc[x]]) lc[x] ^= rc[x] ^= lc[x] ^= rc[x];
    dis[x] = dis[rc[x]] + 1;
    //Size[x] = Size[rc[x]] + Size[rc[y]];
    return x;
}

void Delete(const int x){rt[x] = Merge(lc[x],rc[x]);}

int main()
{
    FileRead(ysqm);
    n = IO::Read();
    for(int i = 1; i <= n ; ++i) fa[i] = i;
    //for(int i = 1; i <= n ; ++i) Size[i] = 1;
    for(int i = 1; i <= n ; ++i) rt[i] = Create(IO::Read());
    m = IO::Read();
    int x,y;
	char opt[2];
    while(m--)
    {
        scanf("%s",opt);
        if(*opt == 'M')
        {
            x = IO::Read();y = IO::Read();
            if(vis[x] || vis[y]) continue;
            x = Find(rt[x]);y = Find(rt[y]);
            if(x != y)
            {
                int nrt = Merge(rt[x],rt[y]);
                fa[nrt == rt[x] ? rt[y] : rt[x]] = nrt == rt[x] ? x : y;
            }
        }
        else if(vis[x = IO::Read()]) printf("0\n");
        else 
        {
        	x = Find(x);
            printf("%d\n",v[rt[x]]);
            rt[x] = Merge(rc[x],lc[x]);
            fa[rt[x]] = rt[x];
            fa[x] = rt[x];
            vis[x] = true;
        }
    }
    return 0;
}
