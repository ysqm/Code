# include <cstdio>
# include <queue>
# include <algorithm>
# define N 20000
# define M 100000
# define R register
using namespace std;
inline int re()
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
	
	return x * f;
}
struct edge
{
	int from,to;
} e[M * 2 + 42],ed[N + 42];
struct STACK
{
	int STACK[N + 42],top = 0;
} S,block;
int n,m = 1,dfn[N + 42],low[N + 42],head[N + 42],t,bt,knt;
long long ans,sum;
bool cut[N + 42];
inline void tarjan(int u,int fa)
{
	dfn[u] = low[u] = ++t;
	S.STACK[++S.top] = u;
	int ch = 0,v;
	
	for(R int i = head[u]; i ;i = e[i].from)
		if(e[i].to != fa){
			
			if(dfn[e[i].to] == 0){
				
				v = e[i].to;
				
				ch++;
				
				tarjan(v,u);
				
				low[u] = min(low[u],low[v]);
				
				if(dfn[u] < low[v] && u != fa) cut[u] = true;
				
				if(dfn[u] < low[v]){
					
					block.top++;
					
					do{
						ed[++bt].from = block.STACK[block.top];
						ed[bt].to = S.STACK[S.top--];
						block.STACK[block.top] = bt;
					}while(S.STACK[S.top + 1] != u);
					
					ed[++bt].from = block.STACK[block.top];
					ed[bt].to = u;
					block.STACK[block.top] = bt;
				}
				
			}
			
			else low[u] = min(low[u],dfn[e[i].to]);
			
		}
	if(u == fa && ch >= 2) cut[u] = true;
}
int main()
{	
	//freopen("testdata (2).in","r",stdin);

	while(m){
		
		m = re();
		knt++;
		
		for(R int i = 1;i <= n;i++)
			head[i] = block.STACK[i] = dfn[i] = 0;
		
		
		n = block.top = 0;
		
		for(R int i = 1,a,b;i <= m ;i++){
			a = re();
			b = re();
			
			n = max(n,max(a,b));
			
			e[i].from = head[a];
			e[i].to = b;
			head[a] = i;
			
			i += m;
			
			e[i].from = head[b];
			e[i].to = a;
			head[b] = i;
			
			i -= m;
			
		}
		
		for(R int i = 1;i <= n;i++)
			if(dfn[i] == 0) tarjan(i,i);
			
		ans  = 0;sum = 1;
		int gn,len;
		
		for(R int i = 1;i <= block.top; i++){
			gn = 0;
			len = 0;
			
			for(R int j = block.STACK[i]; j ;j = ed[i].from){
				len++;
				if(cut[ed[j].to]) gn++;
			}
			
			if(gn == 1){
				ans++;
				sum *= (len - 1);
			}
			else if(gn == 0){
				ans += 2;
				sum *= (len - 1) * len / 2;
			}
		}
		
		printf("Case %d: %lld %lld\n",knt,ans,sum);
		
	}
	
	
	return 0;
}
