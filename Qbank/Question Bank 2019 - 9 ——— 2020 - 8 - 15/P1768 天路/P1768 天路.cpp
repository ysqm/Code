# include <cstdio>
# include <queue>
# define N 2000
# define M 3000
# define R register
# define inf 1000000000
using namespace std;
inline int re()
{
	int f = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
struct edge
{
	int from,to,wi;
} e[2 * M + 42];
long long dis[N + 42],head[N + 42],inq[N + 42];
bool vis[N + 42];
queue <int> q;
int T,n,m;
inline bool SPFA(int s);
int main()
{	
	
}
inline bool SPFA(int s)
{
	for(R int i = 1;i <= n; i++){
		dis[i] = inf;
		inq[i] = 0;
	}
	q.push(s);
	dis[s] = 0;
	int u;
	while(q.size()){
		u = q.front();
		q.pop();
		vis[u] = false;
		for(R int i = head[u]; i ;i = e[i].from)
			if(dis[e[i].to] > e[i].wi + dis[u]){
				dis[e[i].to] = e[i].wi + dis[u];
				if(e[i].to == s || ++inq[e[i].to] > n) return true;
				if(!vis[e[i].to]) {
					q.push(e[i].to);
					vis[e[i].to] = true;
				}
			}
	}
	return false;
}
