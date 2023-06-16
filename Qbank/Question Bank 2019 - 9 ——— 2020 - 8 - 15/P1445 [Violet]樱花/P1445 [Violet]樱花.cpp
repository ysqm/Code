# include <cstdio>
# define mod 1000000007
# define reg register
# define N 1000000

long long ans = 1,n;

int prime[N + 42],tot,v[N + 42];
int vis[N + 42];

int main()
{
	scanf("%lld",&n);
	
	for(reg int i = 2; i <= n; ++i){
		if(!vis[i]) {prime[++tot] = i;vis[i] = i;}
		
		for(reg int j = 1; i * prime[j] <= n && j <= tot; ++j){
			vis[i * prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
	
	//for(reg int i = 1; i <= 100; ++i) printf("%d ",prime[i]);
	
	for(reg int i = 2; i <= n; ++i)
		for(reg int j = i; j != 1 ; j /= vis[j])
			++v[vis[j]];
	
	for(int i = 1; i <= tot && prime[i] <= n; ++i)
			ans = (ans * (((v[prime[i]] * 2 + 1)))) % mod;
	
	printf("%lld",ans);
	return 0;
}
