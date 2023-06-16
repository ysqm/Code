# include <ctime>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define reg register
# define N 20000
# define M 100000
# define Gc getchar()//(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
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
    int u,v,wi;

    edge(const int wi_=0,const int V=0,const int U=0):u(U),v(V),wi(wi_){}
} e[M+5];

int head[N+5],edge_tot = 1,Size[N+5],father[N+5],d[N+5],tot;
int n,m,k;

inline bool comp1(const edge& a,const edge& b){return a.wi < b.wi;}
inline bool comp2(const edge& a,const edge& b){return a.wi > b.wi;}

inline int Find_(const int x){return x == father[x] ? x : father[x] = Find_(father[x]);}
inline void UnionFindPretreatment(){for(reg int i = 1; i <= n ; ++i) Size[i] = 1,father[i] = i;}
inline void Unity(int x,int y)
{
    x = Find_(x);y = Find_(y);
    if(x == y) return ;
    if(Size[x] < Size[y]) x^=y^=x^=y;
    Size[x] += Size[y];father[y] = x;
}

int main()
{
    n = Read();m = Read();k = Read();

    for(reg int i = 1; i <= m ; ++i) e[i] = edge(Read()^1,Read(),Read());

    int cnt = 0;
    UnionFindPretreatment();
    std::sort(e+1,e+m+1,comp1);

    for(reg int i = 1; i <= m ; ++i)
        if(Find_(e[i].u) != Find_(e[i].v))
        {
        	if(e[i].wi == 1) e[i].wi = 3;
            Unity(e[i].u,e[i].v);
            ++cnt;
        }

    if(cnt != n-1) return puts("no solution"),0;

    cnt = 0;
    UnionFindPretreatment();
    std::sort(e+1,e+m+1,comp2);

    for(reg int i = 1; i <= m ; ++i)
        if(Find_(e[i].u) != Find_(e[i].v))
        {
            if(e[i].wi == 1 && cnt == k) continue;
            Unity(e[i].u,e[i].v);
            cnt += (e[i].wi&1);
            d[++tot] = i;
        }

    if(cnt != k) return puts("no solution"),0;

	//puts("Fuck");

    for(reg int i = 1; i <= tot ; ++i) printf("%d %d %d\n",e[d[i]].u,e[d[i]].v,(e[d[i]].wi&1)^1);

    return 0;
}
