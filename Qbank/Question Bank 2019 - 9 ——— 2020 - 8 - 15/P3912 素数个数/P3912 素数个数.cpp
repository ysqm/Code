# include <cstdio>
# define N 1000000
# define reg register

int tot,prime[5800000],n;
bool vis[N + 42];

int main()
{
	scanf("%d",&n);
	
	for(reg int i = 2; i <= n; ++i){
		if(!vis[i]) prime[++tot] = i;
		
		for(reg int j = 1; i * prime[j] <= n && j <= tot; ++j){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	
	printf("%d",tot);
	
	return 0;
}
