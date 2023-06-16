# include <cstdio>
# include <cstring>
# define reg register

int prime[1000042],tot,tai;
bool vis[1000042];

int main()
{
	memset(vis,-1,sizeof(vis));vis[1] = 0;
	
	for(reg int i = 2; i <= 1000042; ++i){
		if(vis[i])prime[++tot] = i;
		
		for(reg int j = 1; i * prime[j] <= 1000042 && j <= tot; ++j){
			vis[i * prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
	
	for(reg int i = 1; i <= 500; ++i) printf("%d ",prime[i]);
	
	int n,a;
	
	while(scanf("%d",&n) && n){
		a = -1;
		for(reg int i = 2; prime[i] <= n; ++i)
			if(vis[n - prime[i]]){a = prime[i];printf("%d = %d + %d\n",n,a,n - a);break;}
	}
	
	return 0;
}
