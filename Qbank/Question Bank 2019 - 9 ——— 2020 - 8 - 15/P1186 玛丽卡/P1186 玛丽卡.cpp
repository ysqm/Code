# include <cstdio>
# include <algorithm>
# include <queue>
using namespace std;
const int N = 1e5,M = 1e6,inf = 1000000000;
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
} e[M+42];
struct Point
{
	int this_dis;
	int this_one;
	bool operator < (const Point  &a) const
	{
		return this_dis>a.this_dis;
	}
};
struct Stack
{
	int data[N + 42];
	int top;
} S;
int head[N + 42];
int n,m;
int dis[N + 42];
int pre[2][N + 42];
priority_queue <Point> q;
void dijkstra1(int s);
void dijkstra(int s);
int main(){
	n = re();
	m = re();
	if(1){
		int a,b,c;
		for(register int i = 1;i <= m; i++){
			a = re();
			b = re();
			c = re();
			e[i].to = b;
			e[i].wi = c;
			e[i].from = head[a];
			head[a] = i;
			e[i + m].to = a;
			e[i + m].wi = c;
			e[i + m].from = head[b];
			head[b] = i + m;
		}
	}
	dijkstra1(n);
	for(register int i = 1; i ; i = pre[0][i])
		S.data[++S.top] = pre[1][i];
	int temp,v,ans = dis[1];
	while(S.top){
		v = S.data[S.top--];
		temp = e[v].wi;
		v = v > m ? v : v + m; 
		e[v].wi = e[v - m].wi = inf;
		dijkstra(n);
		e[v].wi = e[v - m].wi = temp;
		ans = max(ans,dis[1]);
	}
	printf("%d",ans);
	return 0;
}
void dijkstra1(int s)
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
				pre[0][e[i].to] = v;
				pre[1][e[i].to] = i;
				a.this_one = e[i].to;
				a.this_dis = dis[e[i].to];
				q.push(a);
			}
	}
}
void dijkstra(int s)
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
