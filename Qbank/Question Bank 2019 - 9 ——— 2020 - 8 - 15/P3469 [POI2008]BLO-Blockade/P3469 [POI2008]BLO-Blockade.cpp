# include <cstdio>
# include <queue>
# include <algorithm>
# define N 100000
# define M 500000
# define R register
# define LL long long
using namespace std;
inline int re()
{
	int x = 0;
	char c = getchar();
	
	while(c < '0' || c > '9'){
		//if(c == '-') f = -1;
		c = getchar();
	}
	
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	
	return x;
}
struct edge
{
	int from,to;
} e[M * 2 + 42];
int n,m,dfn[N + 42],low[N + 42],head[N + 42],sum,t,siz[N + 42];
LL ans[N + 42];
struct STACK
{
	int STZCK[N + 42],top;
} S;
bool cut[N + 42];
inline void tarjan(int u,int fa)
{
	dfn[u] = low[u] = ++t;
	int ch = 0,sum = 0;
	
	siz[u] = 1;
	
	for(R int i = head[u]; i ;i = e[i].from)
		/*if(e[i].to != fa)*/{
			
			if(dfn[e[i].to] == 0){
				
				ch++;
				
				tarjan(e[i].to,u);
				
				siz[u] += siz[e[i].to];
				
				low[u] = min(low[u],low[e[i].to]);
				
				if(dfn[u] <= low[e[i].to]) {
					ans[u] += (LL)siz[e[i].to] * (n - siz[e[i].to]);
					
					sum += siz[e[i].to];
					
                	cut[u] = true;
				}
				
			}
			
			else low[u] = min(low[u],dfn[e[i].to]);
			
		}
	if(u == fa && ch >= 2) cut[u] = true;
	if(cut[u]) ans[u] += (LL)(n - sum - 1) * (sum + 1) + (n- 1);
    else ans[u] = 2 * (n - 1);
}
int main()
{	
	//freopen("testdata.in","r",stdin);

	n = re();
	m = re();
	
	for(R int i = 1,a,b;i <= m ;i++){
		a = re();
		b = re();
		e[i].from = head[a];
		e[i].to = b;
		head[a] = i;
		i += m;
		e[i].from = head[b];
		e[i].to = a;
		head[b] = i;
		i -= m;
	}
		
	//dfs(1);
	
	/*if(sum < n) {
		printf("0");
		return 0;
	}*/
	
	for(R int i = 1;i <= n;i++)
		if(dfn[i] == 0) tarjan(i,i);
	
	//for(R int i = 1;i <= n;i++) if(cut[i]) sum++;
	
	//printf("%d\n",sum);
	
	for(R int i = 1;i <= n;i++)
		printf("%lld\n",ans[i]);
	
	return 0;
}
