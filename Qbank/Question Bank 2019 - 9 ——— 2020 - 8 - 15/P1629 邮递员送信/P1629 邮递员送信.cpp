# include <cstdio>
# include <queue>
# define inf 0x7f7f7f7f
# define N 1000
# define M 100000
# define reg register
using namespace std;

template <typename T> 
inline void in(T& x)
{
	char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
	
	return x;
}

struct Edge
{
	int from,to,wi;
} e[(M << 1) + 42];

int head[N + 42],opposite_head[N + 42],cnt_e;

inline void add(const int wi,const int v,const int u)
{
	e[++cnt_e].from = head[u];
	
	e[cnt_e].to = v;
	
	e[cnt_e].wi = wi;
	
	head[u] = cnt_e;
	
	e[++cnt_e].from = opposite_head[v];
	
	e[cnt_e].to = u;
	
	e[cnt_e].wi = wi;
	
	opposite_head[v] = cnt_e;
}

queue <int> q;
int dis[N + 42],opposite_dis[N + 42],n,m,ans;
bool inq[N + 42];

int main()
{
	in(n);in(m);
	
	for(reg int i = 1; i <= m ; ++i) add(Read(),Read(),Read());
	
	for(reg int j = 2; j <= n ; ++j) dis[j] = opposite_dis[j] = inf;
	
	q.push(1);reg int u;
	
	while(q.size()){
		u = q.front();q.pop();inq[u] = false;
		
		for(reg int i = head[u]; i ; i = e[i].from)
			if(dis[u] + e[i].wi < dis[e[i].to]){
				dis[e[i].to] = dis[u] + e[i].wi;
				
				if(!inq[e[i].to]){
					inq[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	
	q.push(1);
	
	while(q.size()){
		u = q.front();q.pop();inq[u] = false;
		
		for(reg int i = opposite_head[u]; i ; i = e[i].from)
			if(opposite_dis[u] + e[i].wi < opposite_dis[e[i].to]){
				opposite_dis[e[i].to] = opposite_dis[u] + e[i].wi;
				
				if(!inq[e[i].to]){
					inq[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	
	for(reg int j = 2; j <= n ; ++j) ans += dis[j] + opposite_dis[j];
	
	printf("%d",ans);
	
	return 0;
}
