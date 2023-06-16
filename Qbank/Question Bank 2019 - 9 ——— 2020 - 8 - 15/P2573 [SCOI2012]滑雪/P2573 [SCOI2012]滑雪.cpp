# include <queue> 
# include <cstdio>
# include <cstring>
# include <algorithm>
# define reg register
const int N = 2e6;
const int M = 2e6;
# define LL long long
using namespace std;

inline LL Read()
{
	 LL x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
} 

inline int Min(const int a,const int b){return a < b ? a : b;}
inline int Max(const int a,const int b){return a > b ? a : b;}
inline int ABS(const int a){return a < 0 ? -a : a;} 

int fa[N + 42];
inline int Find(const int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
int H[N + 42];

struct edge
{
	int next,from,to,wi,Tag;
	
	edge(const int next_=0,const int& from_=0,const int to_=0,const int wi_=0,const int Tag_=0):next(next_),from(from_),to(to_),wi(wi_),Tag(Tag_){}
	inline friend bool operator < (const edge& a,const edge& b)
	{
		if(a.Tag != b.Tag) return a.Tag > b.Tag;
		if(H[a.to] != H[b.to]) return H[a.to] > H[b.to];
		return a.wi < b.wi;
	}
} e[M + 42];

int head[N + 42],tot_edge,n,m;

inline void add_edge(const int& u,const int& v,const int& wi)
{
	e[++tot_edge] = edge(head[u],u,v,wi);
	
	head[u] = tot_edge;
}

bool vis[N + 42];
queue<int> q;

inline void BFS()
{
	q.push(1);
	
	vis[1] = 1;
	
	while(q.size())
	{
		int u = q.front();q.pop();
		
		for(int i = head[u] ; i ; i = e[i].next)
		{
			e[i].Tag = 1;
			if(!vis[e[i].to])
			{
				q.push(e[i].to);
				
				vis[e[i].to] = 1;
			}
		}
	}
} 

inline void Kruskal()
{
	for(reg int i = 1; i <= n ; ++i) fa[i] = i;
	
	sort(e + 1,e + tot_edge + 1);
	
	LL ans = 0,sum = 1;
	
	for(reg int i = 1,f1,f2; i <= tot_edge ; ++i)
		if(e[i].Tag && (f1 = Find(e[i].from)) != (f2 = Find(e[i].to)))
		{
			++sum;
			ans += e[i].wi;
			fa[f1] = f2;
		}
	
	printf("%lld %lld",sum,ans);
}

inline void Pretreatment()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i) H[i] = Read();
	
	for(reg int i = 1,x,y,z; i <= m ; ++i)
	{
		x = Read();y = Read();z = Read();
		if(H[x] > H[1] || H[y] > H[1]) continue;
		if(H[x] >= H[y]) add_edge(x,y,z);
		if(H[y] >= H[x]) add_edge(y,x,z);
	}
	
	BFS(); 
} 

int main()
{
	Pretreatment();
	
	Kruskal();
	
	return 0;
}
