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
	int wi;
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
bool book[N+42];
queue <int> q;
void spfa(int s);
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
			e[i].to = b;
			e[i].wi = c;
			e[i].from = head[a];
			head[a] = i;
		}
	}
	spfa(s);
	for(register int i = 1;i <= n;i++)
		printf("%d ", dis[i]);
}
void spfa(int s)
{
	for(register int i = 1;i <= n;i++) dis[i] = inf;
	dis[s] = 0;
	q.push(s);
	book[s] = 1;
	int v;
	while(q.size()){
		v = q.front();
		q.pop();
		book[v] = 0;
		for(register int i = head[v]; i ;i = e[i].from)
			if(dis[v] + e[i].wi < dis[e[i].to]){
				dis[e[i].to] = dis[v] + e[i].wi;
				if(!book[e[i].to]) {
					q.push(e[i].to);
					book[e[i].to] = 1;
				}
			}
	}
}
