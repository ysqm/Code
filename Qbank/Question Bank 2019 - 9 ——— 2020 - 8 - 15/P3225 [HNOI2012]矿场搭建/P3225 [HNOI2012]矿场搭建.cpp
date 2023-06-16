# include <cstdio>
# include <queue>
# include <algorithm>
# define N 500
# define M 250000
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
int n,m = 1,dfn[N + 42],low[N + 42],head[N + 42],t,bt,knt,cnt,num,T,vis[N + 42];
long long ans,sum;
bool cut[N + 42];
inline void tarjan(int u,int fa)
{
	dfn[u] = low[u] = ++t;
	int ch = 0,v;
	
	for(R int i = head[u]; i ;i = e[i].from){
			
			v = e[i].to;
			
			if(dfn[e[i].to] == 0){
				
				ch++;
				
				tarjan(v,u);
				
				low[u] = min(low[u],low[v]);
				
				if((dfn[u] <= low[v] && u != fa) || (u == fa && ch >= 2)) cut[u] = true;
				
			}
			
			else if(v != fa) low[u] = min(low[u],dfn[e[i].to]);
			
		}
}
inline void dfs(int u)
{
	vis[u] = T;
	
	if(cut[u]) return ;
	
	num++;
	
	int v;
	
	
	for(R int i = head[u]; i ;i = e[i].from){
		v = e[i].to;
		
		if(cut[v] && vis[v] != T) cnt++,vis[v] = T; 
         
        if(!vis[v]) dfs(v);
	} 
}
int main()
{	
	//freopen("testdata.in","r",stdin);

	while(m = re()){
		
		for(R int i = 1;i <= n;i++)
			head[i] = dfn[i] = cut[i] = vis[i] = 0;
		
		
		n = 0;
		
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
		
		for(int i = 1;i <= n; i++)
		if(!vis[i] && !cut[i]){
			
			T++;
			
			num = 0;cnt = 0;
			
			dfs(i);
			
			if(cnt == 1){
				ans++;
				sum *= num;
			}
			else if(cnt == 0){
				ans += 2;
				sum *= (num - 1) * num / 2;
			}
		}
		
		printf("Case %d: %lld %lld\n",++knt,ans,sum);
		
	}
	
	
	return 0;
}
