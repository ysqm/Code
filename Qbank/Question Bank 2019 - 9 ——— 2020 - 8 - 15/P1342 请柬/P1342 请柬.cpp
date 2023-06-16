# include <cstdio>
# include <queue>
# define M 1000000
# define inf 2000000000
using namespace std;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct edge
{
	int from,to;
	int wi;
} e[M + 42],e1[M + 42];
struct Point
{
	int this_dis;
	int this_one;
	bool operator < (const Point  &a) const
	{
		return this_dis>a.this_dis;
	}
};
int head[M + 42],dis[M + 42],head1[M + 42],n,m;
bool book[M + 42];
long long ans = 0;
priority_queue <Point> q;
inline void dij(int s);
inline void dij1(int s);
int main()
{
	n = re();
	m = re();
	for(register int i = 1, a, b, c; i <= m; i++){
		a = re();
		b = re();
		c = re();
		e[i].from = head[a];
		e[i].to = b;
		e[i].wi = c;
		head[a] = i;
		e1[i].from = head1[b];
		e1[i].to = a;
		e1[i].wi = c;
		head[b] = i;
	}
	dij(1);
	for(register int i = 1;i <= n; i++) ans += dis[i];
	dij1(1);
	for(register int i = 1;i <= n; i++) ans += dis[i];
	printf("%lld",ans);
	return 0;
} 
inline void dij(int s)
{
	for(register int i = 1;i <= n;i++) dis[i] = inf;
	Point a;
	int v;
	a.this_dis = 0;
	a.this_one = s;
	dis[s] = 0;
	q.push(a);
	while(q.size()){
		a = q.top();
		q.pop();
		v = a.this_one;
		if(dis[v] < a.this_dis) continue;
		for(int i = head[v]; i ;i = e[i].from)
			if(e[i].wi != inf && dis[e[i].to] > dis[v] + e[i].wi){
				dis[e[i].to] = dis[v] + e[i].wi;
				a.this_one = e[i].to;
				a.this_dis = dis[e[i].to];
				q.push(a);
			}
	}
}
inline void dij1(int s){
	for(register int i = 1;i <= n;i++) dis[i] = inf;
	Point a;
	int v;
	a.this_dis = 0;
	a.this_one = s;
	dis[s] = 0;
	q.push(a);
	while(q.size()){
		a = q.top();
		q.pop();
		v = a.this_one;
		if(dis[v] < a.this_dis) continue;
		for(int i = head[v]; i ;i = e1[i].from)
			if(dis[e1[i].to] > dis[v] + e1[i].wi){
				dis[e1[i].to] = dis[v] + e1[i].wi;
				a.this_one = e1[i].to;
				a.this_dis = dis[e1[i].to];
				q.push(a);
			}
	}
}
