# include <cstdio>
# include <algorithm>
# define N 500000
using namespace std;
typedef long long LL;
struct edge
{
	int from,to,wi;
} e[N + 42];
int head[N + 42],n,m,cnt_e;
LL Dp[N + 42][2],cnt,ans;
inline int add(int u,int v,int wi)
{
	e[++cnt_e].from = head[u];
	
	e[cnt_e].to = v;
	
	e[cnt_e].wi = wi;
	
	head[u] = cnt_e;
	
	e[++cnt_e].from = head[v];
	
	e[cnt_e].to = u;
	
	e[cnt_e].wi = wi;
	
	head[v] = cnt_e;
	
	cnt += wi;
}

void dfs(int u,int fa)
{
	int sum1 = 0;
	for(int i = head[u]; i ; i = e[i].from)
		if(e[i].to != fa){
			dfs(e[i].to,u);
			sum1 = Dp[e[i].to][0] + e[i].wi;
			if(sum1 > Dp[u][0]) {
				Dp[u][1] = Dp[u][0];
				Dp[u][0] = sum1;
			}
			else if(sum1 > Dp[u][1]) Dp[u][1] = sum1;
			//printf("Dp[%d][0] = %d Dp[%d][1] = %d\n",u,Dp[u][0],u,Dp[u][1]);
		}
	//printf("Dp[%d][0] = %d Dp[%d][1] = %d\n",u,Dp[u][0],u,Dp[u][1]);
	ans = max(ans,Dp[u][0] + Dp[u][1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	int xu,xv,xwi;
	for(int i = 1;i < n; i++){
		scanf("%d%d%d",&xu,&xv,&xwi);
		add(xu,xv,xwi);
	}
	dfs(m,0);
	printf("%lld",(cnt << 1) - ans);
	return 0;
} 
