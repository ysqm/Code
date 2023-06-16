# include <cstdio> 
# define N 500000
# define R register
inline int r()
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
int h[N + 42],a[N + 42],hq[N + 42],ans[N + 42];
bool vis[N + 42];
struct edge
{
	int from,to;
} e[N + N + 42];
struct que
{
	int from,to,NO;
} q[N + N + 42];
inline int cut(const int i)
{
	if(a[i] == i) return i;
	else return a[i] = cut(a[i]);
}
inline void LCA(const int u)
{
	vis[u] = true;
	for(R int i = h[u] ; i ; i = e[i].from )
		if(!vis[e[i].to]){
			LCA(e[i].to);
			a[cut(e[i].to)] = a[cut(u)];
		}
	for(R int i = hq[u]; i ; i = q[i].from)
		if(vis[q[i].to])
			ans[q[i].NO] = cut(q[i].to);
}
int n,m,s;
int main()
{
	n = r();
	m = r();
	s = r();
	for(R int i = 1,a,b; i < n ; i++){
		a = r();
		b = r();
		e[i].from = h[a];
		e[i].to = b;
		h[a] = i;
		e[i + n].from = h[b];
		e[i + n].to = a;
		h[b] = i + n;
	}
	for(R int i = 1,a,b; i <= m ; i++){
		a = r();
		b = r();
		q[i].from = hq[a];
		q[i].to = b;
		q[i].NO = i;
		hq[a] = i;
		q[i + m].from = hq[b];
		q[i + m].to = a;
		hq[b] = i + m;
		q[i + m].NO = i;
	}
	for(R int i = 1;i <= n; i++) a[i] = i;
	LCA(s);
	for(R int i = 1; i <= m ; i++)
		printf("%d\n",ans[i]);
	return 0;
}
