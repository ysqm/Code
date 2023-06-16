# include <cstdio>
# include <cstring>
# include <cmath>
# define reg register

long long prime[65536],tot,ans;
bool vis[1000042],pri[65536];

int main()
{
	long long L,R;
	scanf("%lld%lld",&L,&R);
	
	for(reg int i = 2; i <= 50000; ++i){
		if(!pri[i])prime[++tot] = i;
		
		for(reg int j = 1; i * prime[j] <= 50000 && j < tot; ++j){
			pri[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	
	long long len = R - L + 1;
	
	for(reg int i = 1; i <= tot; ++i)
		for(reg long long j = (L + prime[i] - 1) / prime[i] * prime[i] > 2 * prime[i] ? (L + prime[i] - 1) / prime[i] * prime[i] : 2 * prime[i]; j <= R; j += prime[i]) 
			vis[j - L + 1] = 1;
			
	for(reg int i = 1; i <= len ; ++i) if(!vis[i]) ++ans;
		
	printf("%lld",ans);
	
	return 0;
}
