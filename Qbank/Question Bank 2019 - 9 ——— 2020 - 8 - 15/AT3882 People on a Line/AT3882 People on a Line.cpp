# include <cstdio>
# include <queue>
# define N 100000
# define M 200000
# define R register
# define inf 1000000000
# define C const int
using namespace std;
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
	
	return x *= f;
}
struct edge
{
	int from,to,wi;
} e[2 * M + 42];
long long dis[N + 42],head[N + 42],cnt;
bool vis[N + 42],flag;

inline void add(C u,C v,C wi)
{
	e[++cnt].from = head[u];
	e[cnt].to = v;
	e[cnt].wi = wi;
	head[u] = cnt;
}

queue <int> q;
int n,m;
inline bool SPFA(int s);
int main()
{	
	n = r();m = r();
	
	int a,b,c;
	while(m--){
		a = r();b = r();c = r();
		add(a,b,c);
		add(b,a,-c);
	}
	
	for(R int i = 1;i <= n;i++)
		if(!vis[i] && SPFA(i)) break;
	
	if(flag == false) puts("Yes");
	else puts("No");
}
inline bool SPFA(int s)
{
	if(flag) return true;
    vis[s] = true;
    int v;
    for(int i = head[s]; i ; i = e[i].from)
    {
    	v = e[i].to;
        if(!vis[v]) dis[v] = dis[s] + e[i].wi,SPFA(v);
        else if(dis[v] != dis[s] + e[i].wi) return flag = true;
    }
    return false;
}
