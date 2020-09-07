# include <cstdio>
# include <algorithm>
# include <queue>
using namespace std;
const int N = 1e5,M = 5e5,inf = 2147483647;
inline int re()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
/*struct edge
{
	int from,to;
	int wi;
} e[M+42];*/
struct edge
{
	int u,v;
	int w;
} e[M+42];
/*struct Point
{
	int this_dis;
	int this_one;
	bool operator < (const Point &a) const
	{
		return this_dis>a.this_dis;
	}
};*/
int head[N+42];
int n,m,s;
int dis[N+42];
//priority_queue <Point> q;
void dijkstra(int s);
void bell_ford(int s);
int main(){
	n = re();
	m = re();
	s = re();
	if(1){
		int a,b,c;
		for(register int i = 1;i <= m; i++){
			a = re();
			b = re();
			c = re();
			e[i].v = b;
			e[i].u = a;
			e[i].w = c;
			/*e[i].to = b;
			e[i].wi = c;
			e[i].from = head[a];
			head[a] = i;*/
		}
	}
	//dijkstra(s);
	bell_ford(s);
	for(register int i = 1;i <= n;i++)
		printf("%d ", dis[i]);
}
/*void dijkstra(int s)
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
			if(dis[e[i].to] > dis[v] + e[i].wi){
				dis[e[i].to] = dis[v] + e[i].wi;
				a.this_one = e[i].to;
				a.this_dis = dis[e[i].to];
				q.push(a);
			}
	}
}*/
void bell_ford(int s)
{
	for(register int i = 1;i <= n;i++) dis[i] = inf;
	dis[s] = 0;
	bool flag = true;
	for(int i = 1;i < n; i++){
		for(int j = 1; j <= n; j++)
			if(dis[e[j].u] != inf && dis[e[j].u] + e[j].w < dis[e[j].v]){
				dis[e[j].v] = dis[e[j].u] + e[j].w;
				flag = false;
			}
		if(flag) break;
		flag = true;
	}
}
