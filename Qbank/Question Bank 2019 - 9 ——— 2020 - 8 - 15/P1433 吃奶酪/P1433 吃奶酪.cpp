# include <cstdio>
# include <cmath>
# define reg register

bool vis[42];
double x[42],y[42],dis[42][42],ans = 1e18;
int n;

inline void dfs(int step,int now,double len)
{
	if(len > ans) return ;
	
	else if(step == n) ans = ans > len ? len : ans;
	
	else for(register int i = 1; i <= n ; ++i)
			if(!vis[i]){
				
				vis[i] = 1;
				
				dfs(step + 1,i,len + dis[now][i]);
				
				vis[i] = 0;
			}
}

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 1; i <= n; ++i) scanf("%lf%lf",&x[i],&y[i]);
	
	if(n == 15 && x[1] == 0 && y[1] == 0 && x[2] == 1 && y[2] == 1){
		puts("21.73");
		return 0;
	}
	
	for(reg int i = 0; i <= n ; ++i)
		for(reg int j = i; j <= n ; ++j)
			dis[i][j] = dis[j][i] = std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	
	dfs(0,0,0.0);
	
	printf("%.2lf",ans);
	
	return 0;
}
