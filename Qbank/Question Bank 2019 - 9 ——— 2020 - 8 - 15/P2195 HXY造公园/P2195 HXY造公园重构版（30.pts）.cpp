# include <cstdio>
# include <cstring>
# define reg register
# define N 300000
# define LL long long

inline int Read()
{
	 int x = 0;char ch = getchar();
	 
	 while(ch < '0' || ch > '9') ch = getchar();
	 
	 while(ch >= '0' && ch <= '9'){x = (x * 10) + (ch ^ 48);ch = getchar();}
	 
	 return x;
}

int father[N + 42];

template <class T> inline T Min(const T a,const T b){return a < b ? a : b;}
template <class T> inline T Max(const T a,const T b){return a > b ? a : b;}
int Find(int x)
{
	int temp = x;
	
	while(temp != father[temp]) 
		temp = father[temp];
	
	father[x] = temp;
	
	while(x != temp) father[x = father[x]] = temp;
	
	return x;
} 

struct edge
{
	int next,to;
	
	edge(const int next_=0,const int to_=0):next(next_),to(to_){}
} e[(N << 1) + 42];

int head[N + 42],tot_edge,n,m,Q;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
	
	father[Find(u)] = Find(v);
}

int dp[N + 42],d[N + 42];

int Dp(const int& u,const int& fa)
{
	int tmp = 0;
	
	for(reg int i = head[u]; i ; i = e[i].next)
		if(e[i].to != fa)
		{
			Dp(e[i].to,u);
			
			int val = dp[e[i].to] + 1;
			
			if(val > dp[u]) {tmp = dp[u];dp[u] = val;}
			else if(val > tmp) tmp = val;
		}
	
	d[u] = Max(d[u],dp[u] + tmp);
}

inline void Merge(int x,int y)
{
	x = Find(x);y = Find(y);
	
	if(x == y) return ;
	
	d[x] = Max(d[x],Max(dp[y],((d[x]+1)>>1)+((d[y]+1)>>1)+1));
	
	father[y] = x;
}

int main()
{
	n = Read();m = Read();Q = Read();
	
	for(reg int i = 1; i <= n ; ++i) father[i] = i;
	
	for(reg int i = 1; i <=  m ; ++i) add_edge(Read(),Read());
	
	for(reg int i = 1; i <= n ; ++i) if(Find(i) == i) Dp(i,i);
	
	while(Q--)
	{
		if(Read() == 1) printf("%d\n",d[Find(Read())]);
		else Merge(Read(),Read());
	}
	
	return 0;
}
