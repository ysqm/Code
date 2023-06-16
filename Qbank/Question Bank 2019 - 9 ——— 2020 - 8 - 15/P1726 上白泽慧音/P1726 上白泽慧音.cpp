# include <cstdio>
# include <algorithm>
# include <queue>
using namespace std;
# define N 5000
# define M 50000
# define R register
inline int r()
{
	int x = 0,f = 1;
	char c = getchar();
	
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		else f = 1;
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	
	return x * f;
}

int dfn[N + 42],t,head[N + 42],n,m,colour,co[N + 42],osu[N + 42];
bool ins[N + 42];

int cnt;

//priority_queue <int> q1,q2;

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
		//printf("强连通分量%d:\n",++cnt);
		
		low.top--;
		colour++;
		
		do{
			//q2.push(s.Stack[s.top]);
			p = s.Stack[s.top--];
			osu[colour]++;
			co[p] = colour;
			//printf("%d ",p);
			ins[p] = false;
		}while(p != u);
		
		//printf("\n");
	}
	
	return;
}

int main()
{
	s.top = low.top = 0;
	//freopen("1.in","r",stdin);
	n = r();
	m = r();
	
	for(R int i = 1,a,b,c; i <= m ;i++){
		a = r();
		b = r();
		c = r();
		
		if(c == 2){
			i += m;
			e[i].from = head[b];
			e[i].to = a;
			head[b] = i;
			i -= m;
		} 
		
		e[i].from = head[a];
		e[i].to = b;
		head[a] = i;
	}
	
	for(R int i = 1;i <= n; i++)
		if(dfn[i] == 0) tarjan(i);
	
	int ans = 0;
	
	for(R int i = 1;i <= n; i++)
		if(ans < osu[i]) ans = osu[i];
	
	printf("%d\n",ans);
	
	for(R int i = 1;i <= n; i++){
		if(osu[co[i]] == ans){
			int T = co[i];
			
			for(R int j = i;j <= n; j++)
				if(T == co[j])
					printf("%d ",j);
					
			return 0;
		}
	}
	return 0;
}
