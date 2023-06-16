# include <cstdio>
# include <algorithm>
# include <cmath>
# define N 500000
# define M 500000
# define R register
using namespace std;

inline int r()
{
	int f = 1,x = 0;char c = getchar();
	
	while(c > '9' || c < '0'){if(c == '-') f = -1;c = getchar();}
	
	while(c >= '0' && c <= '9'){x = (x << 3) + (x << 1) + c - '0';c = getchar();}
	
	return x * f;
}

struct edge
{
	int from,to;
} e[(M << 1) + 42];

int head[N + 42],e_cnt,n,m,s,deep[N + 42],son[N + 42],dad[N + 42],siz[N + 42],top[N + 42];

inline void add(int u,int v)
{
	e[++e_cnt].from = head[u];
	
	e[e_cnt].to = v;
	
	//e[e_cnt].wi = wi;
	
	head[u] = e_cnt;
	
	e[++e_cnt].from = head[v];
	
	e[e_cnt].to = u;
	
	//e[e_cnt].wi = wi;
	
	head[v] = e_cnt;
	
}

void LCT_INIT(int u)
{
	siz[u] = 1; son[u] = 0;
	
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != dad[u]){
			dad[e[i].to] = u;
			
			deep[e[i].to] = deep[u] + 1;
			
			LCT_INIT(e[i].to);
			
			siz[u] += siz[e[i].to];
			
			if(siz[e[i].to] > siz[son[u]]) son[u] = e[i].to;
		}
}

void LCT(int u,int sign)
{
	top[u] = sign;
	
	if(son[u]) LCT(son[u],sign);
	
	for(R int i = head[u]; i ;i = e[i].from)
		if(e[i].to != son[u] && e[i].to != dad[u]) LCT(e[i].to,e[i].to);
}

inline int LCA(int x,int y)
{
	while(top[x] != top[y]) deep[top[x]] > deep[top[y]] ? x = dad[top[x]] : y = dad[top[y]];
	
	return deep[x] > deep[y] ? y : x;
}

int main()
{
	n = r();m = r();s = r();
	
	n--;
	
	while(n--) add(r(),r());
	
	deep[s] = 0;
	
	LCT_INIT(s);
	
	LCT(s,s);
	
	while(m--) printf("%d\n",LCA(r(),r()));
	
	return 0;
} 
