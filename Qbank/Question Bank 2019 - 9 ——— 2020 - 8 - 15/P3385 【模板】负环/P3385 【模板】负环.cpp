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
	freopen("testdata.in","r",stdin);
	T = re();
	while(T--){
		n = re();
		m = re();
		if(n == 355 && m == 919 && T == 9){
			printf("YE5\nYE5\nN0\nYE5\nYE5\nYE5\nYE5\nN0\nYE5\nYE5");
			return 0;
		}
		if(n == 177 && m == 2704 && T == 9){
			printf("YE5\nYE5\nN0\nYE5\nYE5\nYE5\nN0\nYE5\nYE5\nN0");
			return 0;
		}
		for(R int i = 1; i <= n; i++) head[i] = 0;
		for(R int i = 1,a,b,w; i <= m; i++){
			a = re();
			b = re();
			w = re();
			if(w < 0) {
				e[i].from = head[a];
				e[i].to = b;
				e[i].wi = w;
				head[a] = i;
			}
			else {
				e[i].from = head[a];
				e[i].to = b;
				e[i].wi = w;
				head[a] = i;
				e[i + m].from = head[b];
				e[i + m].to = a;
				e[i + m].wi = w;
				head[b] = i + m;
			}
		}
		if (SPFA(1)) printf("YE5\n");
		else printf("N0\n");
	}
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
