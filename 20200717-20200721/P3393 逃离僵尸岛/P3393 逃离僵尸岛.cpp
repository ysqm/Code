# include <cstdio>
# include <queue>
# include <cstring>
# define reg register 
# define N 100000
# define M 200000
# define LL long long

inline int Read()
{
	int x = 0,f = 1;char ch = getchar();
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return f == -1 ? -x : x;
}

struct edge
{
	int Next,to;
	
	edge(const int Next_=0,const int To_=0):Next(Next_),to(To_){}
	
} e[(M << 1) + 42];

int head[N + 42],tot_edge;

inline void add_edge(const int u,const int v)
{
	e[++tot_edge] = edge(head[u],v);
	
	head[u] = tot_edge;
	
	e[++tot_edge] = edge(head[v],u);
	
	head[v] = tot_edge;
}

inline int Max(const int a,const int b){return a < b ? b : a;} 

bool vis[N + 42],inq[N + 42];
int Danger[N + 42];
int n,m,k,s,P,Q;
LL dis[N + 42],W[N + 42];

std::queue <int> q;

void SPFA(const int S)
{
	q.push(S);
	
	inq[S] = 1;
	
	memset(dis,0x3f,sizeof(dis));
	
	dis[S] = 0;
	
	while(q.size())
	{
		int u = q.front();q.pop();
		
		inq[u] = 0;
		
		for(int i = head[u]; i ; i = e[i].Next)
			if(dis[e[i].to] > dis[u] + W[e[i].to])
			{
				dis[e[i].to] = dis[u] + W[e[i].to];
				
				if(inq[e[i].to] == 0)
				{
					q.push(e[i].to);
					inq[e[i].to] = 1;
				}
			}
	}
}

int main()
{
	freopen("P3393_4.in","r",stdin);
	
	n = Read();m = Read();k = Read();s = Read();
	
	P = Read();Q = Read();
	
	for(reg int i = 1; i <= n ; ++i) W[i] = 1;
	
	for(reg int i = 1; i <= n ; ++i) Danger[i] = i;
	
	for(reg int i = 1; i <= k ; ++i) Danger[Read()] = n+1;
	
	for(reg int i = 1; i <= m ; ++i) add_edge(Danger[Read()],Danger[Read()]);
	
	SPFA(n+1);
	
	for(reg int i = 1; i <= n ; ++i) dis[i] <= s ? W[i] = Q : W[i] = P;
	
	W[n+1] = 1e16;
	
	W[1] = 0;
	W[n] = 0;
	
	SPFA(1);
	
	printf("%lld",dis[n]);
	
	return 0;
}
