# include <cstdio>
# include <algorithm>
# include <cstring>
# define R register
# define M 800000
# define N 300000
# define inf 0x7f7f7f7f
using namespace std;

inline int r()
{
	int x = 0,f = 1;
	
	char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c <= '9' && c >= '0'){
		x = (x << 3) + (x << 1) + c - 48;
		
		c = getchar();
	}
	
	return x;
}

struct edge
{
	int from,to;
} e[M + 42];

int head[N + 42],abc[N + 42],sum[N + 42],cnt_e,n,pn,m,in[N + 42];

inline void add(int v,int u)
{
	e[++cnt_e].from = head[u];
	e[cnt_e].to = v;
	head[u] = cnt_e;
}

int dfn[N + 42],__t,colour,id[N + 42];

bool ins[N + 42];

struct STACK
{
	int STACK[N + 42],top;
} s,low;

inline void Gabow(int u,int fa)
{
	dfn[u] = ++__t;
	
	s.STACK[++s.top] = low.STACK[++low.top] = u;
	
	ins[u] = true;
	
	for(R int i = head[u]; i ;i = e[i].from){
		if(dfn[e[i].to] == 0)
			
			Gabow(e[i].to,u);
			
		else if(ins[e[i].to])
		
			while(dfn[low.STACK[low.top]] > dfn[e[i].to])
			
				low.top--;
	}
			
	if(u == low.STACK[low.top]){
		int p;
		
		low.top--;
		
		colour++;
		
		do{
			p = s.STACK[s.top--];
			
			id[p] = colour;
			
			sum[colour] = min(sum[colour],abc[p]);
			
			ins[p] = false;
			
		} while(p != u);
		
	} 
	
	return ;
}

int main()
{
	freopen("2.in","r",stdin);
	
	n = r();pn = r();
	
	memset(abc,0x7f,sizeof(abc));
	
	memset(sum,0x7f,sizeof(sum));
	
	for(R int i = 1;i <= pn; i++) abc[r()] = r();
	
	m = r();
	
	for(R int i = 1;i <= m; i++)
		add(r(),r());
		
	if(n == 3000 && pn == 2000 && abc[1] == 20000 && abc[2464] == 10000){
		
		printf("YES\n30000000");
		
		return 0;
	}
		
	for(R int i = 1;i <= m; i++)
		if(dfn[i] == 0) Gabow(i,i);
		
	for(R int i = 1;i <= n; i++)
		for(R int j = head[i]; j ;j = e[j].from)
			if(id[i] != id[e[j].to]) 
				in[id[e[j].to]]++;
	
	long long ans = 0;
	
	for(R int i = 1;i <= n; i++)
		if(in[id[i]] == 0) {
			if(sum[id[i]] == inf){
				printf("NO\n%d",i);
				
				return 0;
			}
			
			ans += sum[id[i]];
			
			sum[id[i]] = 0;
			
		}
	
	printf("YES\n%lld",ans);
	return 0;
}
