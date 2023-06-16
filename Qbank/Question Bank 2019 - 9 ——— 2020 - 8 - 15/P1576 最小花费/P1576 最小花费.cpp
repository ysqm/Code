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
int head[N+42];
int n,m,s,t;
double dis[N+42];
bool book[N+42];
priority_queue <Point> q;
void dijkstra(int s);
int main(){
	freopen("testdata.in","r",stdin);
	n = re();
	m = re();
	if(1){
		int a,b,c;
		for(register int i = 1;i <= m; i++){
			a = re();
			b = re();
			c = re();
			e[i].to = b;
			e[i].wi = 1-c/100.0;
			e[i].from = head[a];
			head[a] = i;
			e[i + m].to = a;
			e[i + m].wi = 1-c/100.0;
			e[i + m].from = head[b];
			head[b] = i + m;
		}
	}
	t = re();
	s = re();
	dijkstra(s);
	//for(register int i = 1;i <= n;i++)
	printf("%.8lf",dis[t]);/*.8lf*/
}
void dijkstra(int s)
{
	for(register int i = 1;i <= n;i++) dis[i] = inf;
	Point a;
	int v;
	a.this_dis = 100.0;
	a.this_one = s;
	dis[s] = 100.0;
	q.push(a);
	while(q.size()){
		a = q.top();
		q.pop();
		v = a.this_one;
		if(book[v]) continue;
		book[v] = 1;
		for(int i = head[v]; i ;i = e[i].from)
			if(dis[e[i].to] > dis[v] / e[i].wi){
				dis[e[i].to] = dis[v] / e[i].wi;
				a.this_one = e[i].to;
				a.this_dis = dis[e[i].to];
				q.push(a);
			}
	}
}
