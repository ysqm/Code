# include <cstdio>
# define N 1000000
# define reg register

int prime[N + 42],n,tot;
bool vis[N + 42];

int main()
{
	vis[1] = 1;
	
	scanf("%d",&n);
	
	if(n < 3){
		puts("1");
		n == 2 ? puts("1 1") : puts("1");
		return 0;
	}
	
	++n;
	
	for(reg int i = 2; i <= N; ++i){
		if(!vis[i]) prime[++tot] = i;
		
		for(reg int j = 1; i * prime[j] <= N && j <= tot; ++j){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}

	puts("2");
	
	for(reg int i = 2; i <= n; ++i) printf("%d ",vis[i] + 1);
	return 0;
}

