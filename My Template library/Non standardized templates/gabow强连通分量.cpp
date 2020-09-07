# include <cstdio>
# include <algorithm>
using namespace std;
# define N 10000
# define M 50000
# define R register
inline int r()
{
	int x = 0,f = 1;
	char c = getchar();
	
	while(c > '9' || c < '0'){
		if(c = '-') f = -1;
		else f = 1;
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
	return x * f;
}

int dfn[N + 42],t,head[N + 42],n,m;
bool ins[N + 42];

int cnt;

struct edge
{
	int from,to;
} e[M + 42];

struct STACK
{
	int Stack[N + 42],top;
} s,low;

inline void tarjan(int u)
{
	dfn[u] = ++t;
	s.Stack[++s.top] = low.Stack[++low.top] = u;
	ins[u] = true;
	
	for(R int i = head[u]; i ;i = e[i].from)
	{
		if(dfn[e[i].to] == 0) tarjan(e[i].to);
		
		else if(ins[e[i].to]) while(dfn[low.Stack[low.top]] > dfn[e[i].to]) low.top--;
		
	}
	if(u == low.Stack[low.top]){
		int p;
		printf("强连通分量%d:\n",++cnt);
		
		low.top--;
		
		do{
			p = s.Stack[s.top--];
			printf("%d ",p);
			ins[p] = false;
		}while(p != u);
		
		printf("\n");
	}
	
	return;
}

int main()
{
	s.top = low.top = 0;
	freopen("3.txt","r",stdin);
	n = r();
	m = r();
	
	for(R int i = 1,a,b; i <= m ;i++){
		a = r();
		b = r();
		
		e[i].from = head[a];
		e[i].to = b;
		head[a] = i;
	}
	
	for(R int i = 1;i <= n; i++)
		if(dfn[i] == 0) tarjan(i);
		
	
	return 0;
}
