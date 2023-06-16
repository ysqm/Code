# include <cstdio>
# include <algorithm>
# include <queue> 
using namespace std;
# define N 100000
# define M 100000
# define R register
# define inf 1000000000
# define f(i,n,m) for(register int i = m;i <= n; i++)

int dis[N + 42],head[N + 42],cnt;

bool vis[N + 42];

struct edge
{
	int from,to,wi;
} e[M * 2 + N + 42];

int n,m;

inline int r(int &x);
 
inline bool SPFA(int s);

inline void add(int u,int v,int wi)
{
	e[++cnt].from = head[u];
	e[cnt].to = v;
	e[cnt].wi = wi;
	head[u] = cnt;
}

int main()
{
	freopen("1.in","r",stdin); 
	r(n);
	r(m);
	
	int d,a,b,c;
	while(m--){
		r(d);r(a);r(b);
		if(d == 1){
			r(c);//b -> a 一条 c 的边 
			add(b,a,c);
			
		}
		else if(d == 2){
			r(c);
			add(a,b,-c);
		}//a -> b 一条 -c 的边
		else{
			add(a,b,0);
			add(b,a,0);
		}
	}
	
	for(R int i = 1;i <= n; i++) add(0,i,0),dis[i] = -inf;
	
	if(SPFA(0)) printf("No");
	else printf("Yes");
	return 0;
}
inline int r(int &x)
{
	x = 0;
	int f = 1;
	char c = getchar();
	
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		else f = 1;
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
}
inline bool SPFA(int u)
{
		vis[u] = true;
		for(R int i = head[u]; i ; i = e[i].from )
			if(dis[e[i].to] < dis[u] + e[i].wi){
				dis[e[i].to] = dis[u] + e[i].wi;
				if(vis[e[i].to]) return true;
				else if(SPFA(e[i].to)) return true;
			}
		vis[u] = false;
	return false;
}
