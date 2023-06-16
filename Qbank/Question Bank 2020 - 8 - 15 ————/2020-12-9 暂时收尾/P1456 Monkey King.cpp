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

int ls[N+5],rs[N+5],v[N+5],dis[N+5],tot,rt[N+5];

int Find(const int x){return x == rt[x] ? x : rt[x] = Find(rt[x]);}

void Create(const int Val)
{
    ++tot;
    rt[tot] = tot;
    dis[tot] = ls[tot] = rs[tot] = 0;
    v[tot] = Val;
}

int Merge(int x,int y)
{
    if(x == 0 || y == 0) return x+y;
    if(v[x] < v[y]) y ^= x ^= y ^= x;
    rs[x] = Merge(rs[x],y);
    rt[rs[x]] = x;
    if(dis[ls[x]] < dis[rs[x]]) ls[x] ^= rs[x] ^= ls[x] ^= rs[x];
    dis[x] = dis[rs[x]]+1;
    return x;
}

void Pop(const int x)
{
    rt[x] = Merge(ls[x],rs[x]);
    rt[rt[x]] = rt[x];
    ls[x] = rs[x] = 0;
    //vis[x] = true;
}


int Fight(const int x,const int y)
{
	if(x == y) return -1;
    Pop(x);
    v[x] /= 2;
    rt[x] = Merge(rt[x],x);
    Pop(y);
    v[y] /= 2;
    rt[y] = Merge(rt[y],y);
    return v[rt[x] = rt[y] = Merge(rt[x],rt[y])];
}

int n,x,y,m;

int main()
{
    FileRead(ysqm);
    FileWrite(myans);
    while(scanf("%d",&n) != EOF)
    {
    	tot = 0;
    	for(int i = 1; i <= n ; ++i) Create(IO::Read());
    	m = IO::Read();
    	while(m--)
    	{
        	x = IO::Read();y = IO::Read();
        	printf("%d\n",Fight(Find(x),Find(y)));
    	}
	}
    
    return 0;
}