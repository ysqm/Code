# include <cstdio>
# include <algorithm>
# include <queue>
# include <cmath> 
using namespace std;
const int N = 1e5,M = 5e5,inf = 2147483647;
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
	double wi;
} e[M+42];
struct Point
{
	double this_dis;
	int this_one;
	bool operator < (const Point &a) const
	{
		return this_dis>a.this_dis;
	}
};
int head[N + 42];
int n,m,s,pre[N + 42][2],ans = 1,E[M + 42];
double dis[N + 42];
priority_queue <Point> q;
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
			e[i].wi = log10(c);
			e[i].from = head[a];
			head[a] = i;
			E[i] = c;
		}
	}
	dijkstra(1);
	for(register int i = n; pre[i][0] ;i = pre[i][0])
		ans = (ans * pre[i][1]) % 9987;
	printf("%d",ans);
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
			if(dis[e[i].to] > dis[v] + e[i].wi){
				dis[e[i].to] = dis[v] + e[i].wi;
				pre[e[i].to][0] = v;
				pre[e[i].to][1] = E[i];
				a.this_one = e[i].to;
				a.this_dis = dis[e[i].to];
				q.push(a);
			}
	}
}
