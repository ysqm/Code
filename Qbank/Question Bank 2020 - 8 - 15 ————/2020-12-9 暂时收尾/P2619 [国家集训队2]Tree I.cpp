# include <queue>
# include <cmath>
# include <cstring>
# include <cstdio>
# include <algorithm>
//# define Calc(L,R) Get_Wi(L,R,(L+R)/2)
const int N = 5e5;

inline int Read()
{
    register int x = 0;char ch = getchar();
    
    while(ch < '0' || ch > '9')ch = getchar();
    
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = getchar();}
    
    return x;
}

const int Max_N = 5e4;
const int Max_E = 1e5;

int Min(const int x,const int y){return x < y ? x : y;}
int Max(const int x,const int y){return x < y ? y : x;}

struct edge
{
    int Color,U,V,Wi;
    edge(const int Next_=0,const int to_=0,const int wi_=0,const int Color_=0):U(Next_),V(to_),Wi(wi_),Color(Color_){}
} e[Max_E+5];
bool operator < (const edge& a,const edge& b){return a.Color != b.Color ? b.Color < a.Color : b.Wi > a.Wi;}
int edge_tot,n,m,Need,numblack,ans,Ans;
int f[N+5],sz[N+5];
void UnionFind(const int n=0)
{
	for(int i = 1; i <= n ; ++i) 
		*(f+i) = i,*(sz+i) = 1;
}
int Find(const int x)
{	
	return x == *(f+x) ? x : (*(f+x) = Find(*(f+x)));
}
void Unity(int x,int y)
{
    x = Find(x);y = Find(y);
    if(x == y) return;
    if(*(sz+x) < *(sz+y)) x^=y^=x^=y;
    *(sz+x) += *(sz+y);
    *(f+y) = x;
}
# define Intree(x) (Find(x.U) == Find(x.V))


int Krusal(const int wi)
{
    UnionFind(n);Ans = 0;
    int pw = numblack+1,pb = 1,res = 0;
    int cse = 0;
    while(cse+1 != n)
    {
    	++cse;
    	/*if(cse>790)
		{
			int idx;
			++idx;
		}*/
    	while(Intree(e[pb]) && pb <= numblack) ++pb;
        while(Intree(e[pw]) && pw <= edge_tot) ++pw;
        if(pb <= numblack && pw <= edge_tot)
        {
            if(e[pw].Wi+wi <= e[pb].Wi){Unity(e[pw].U,e[pw].V);Ans += e[pw].Wi+wi;++res;}
			else {Unity(e[pb].U,e[pb].V);Ans += e[pb].Wi;}
            
        }
        else if(pb <= numblack){Unity(e[pb].U,e[pb].V);Ans += e[pb].Wi;}
        else {Unity(e[pw].U,e[pw].V);Ans += e[pw].Wi+wi;++res;}
	}
    return res;
}

int main()
{
    n = Read();m = Read();Need = Read();
    for(int i = 1,x,y,z; i <= m ; ++i)
    {
        x = Read()+1;y = Read()+1;z = Read();
        e[++edge_tot] = edge(x,y,z,Read());numblack += e[edge_tot].Color;
    }
    std::sort(e+1,e+m+1);
    int l = -111,r = 111,mid,res;
    while(l <= r)
    {
        mid = (l+r)/2;
        res = Krusal(mid);
        if(res >= Need) l = (ans = mid)+1;
        else r = mid-1;
    }
    Krusal(ans);
    printf("%d\n",Ans-ans*Need);
    return 0;
}
