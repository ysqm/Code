/*
	压行的代码
	不注意格式 
*/
# include <cstdio>
# include <algorithm>
# define LL long long
# define R register
# define N 500000
using namespace std;
inline int r(){int x = 0;char c = getchar();while(c < '0' || c > '9') c = getchar();while(c <= '9' && c >= '0') {x = x * 10 - 48 + c;c = getchar();}return x;} 
LL deep[N + 42],ans,dp[N + 42];int n,head[N + 42],cnt,s;
struct edge {int from,to,wi;} e[N * 2 + 24]; 
inline void add(int wi,int v,int u){e[++cnt].to = v;e[cnt].from = head[u];e[cnt].wi = wi;head[u] = cnt;e[++cnt].to = u;e[cnt].from = head[v];e[cnt].wi = wi;head[v] = cnt;}
inline void dfs1(int u,int fa){
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != fa){
			dfs1(e[i].to,u);
			deep[u] = max(deep[e[i].to] + e[i].wi,deep[u]);
		}
}
inline void dfs2(int u,int fa){
	for(R int i = head[u]; i ; i = e[i].from)
		if(e[i].to != fa){
			dfs2(e[i].to,u);
			ans += deep[u] - e[i].wi - deep[e[i].to];
		}
}
int main(){
	n = r(); s = r();
	
	for(R int i = 1; i < n; i++) add(r(),r(),r());
	
	dfs1(s,0);
	
	dfs2(s,0);
	
	printf("%lld",ans);
	
	return 0;
}
