# include <cstdio>
# include <algorithm>
# include <queue>
using namespace std;
typedef long long LL;
const int N = 1e5,M = 1e5;
const LL inf = 9223372036854775806;
inline LL re()
{
    LL x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
struct edge
{
	int from,to;
	LL wi;
} e[M*2+42];
struct Point
{
	int this_dis;
	int this_one;
	bool operator < (const Point &a) const
	{
		return this_dis>a.this_dis;
	}
};
LL head[N+42];
LL n,m,s,pre[N+42],an[N+42],k = 0;
LL dis[N+42];
priority_queue <Point> q;
void dijkstra(int s);
void show(int i);
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
	dijkstra(1);
	if(dis[n] == inf) printf("-1");
	else {
		int i = n;
		while(i) an[k++] = i,i = pre[i];
		i = k-1;
		while(i)printf("%lld ",an[i--]);
		printf("%lld",an[i]);
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
			if(dis[e[i].to] > dis[v] + e[i].wi){
				dis[e[i].to] = dis[v] + e[i].wi;
				a.this_one = e[i].to;
				pre[e[i].to] = v;
				a.this_dis = dis[e[i].to];
				q.push(a);
			}
	}
}
