# include <cstdio>
# define reg register 
# define N 10000000
# define LL long long
# define int long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

bool vis[N + 42];
int phi[N + 42],prime[N + 42],tot; 

inline int fast_pow(reg LL x,reg int p,reg int mod)
{
	reg LL res = 1;
	for(; p ; p>>=1,x=(x*x)%mod)
		if(p&1) res = (res*x)%mod;
	return res;
}

inline LL dfs(const int mod)
{
	if(mod == 1) return 0;
	else if(mod == 2) return 0;
	else return fast_pow(2,dfs(phi[mod])+phi[mod],mod);
}

signed main()
{
	vis[1] = 1;
	phi[1] = 1;
	
	for(reg int i = 2; i <= N; ++i)
	{
		if(!vis[i])
		{
			prime[++tot] = i;
			
			phi[i] = i-1;
		}
		for(reg int j = 1 ; j <= tot && i * prime[j] <= N ; ++j)
		{
			vis[i*prime[j]] = 1;
			if(i % prime[j] == 0) {phi[i*prime[j]] = phi[i] * prime[j];break;}
			else phi[i*prime[j]] = phi[i] * phi[prime[j]];
		}
	}
	//printf("%d",phi[1000]); 
	reg int T = Read();
	
	//for(reg int i = 1; i <= T ; ++i) printf("%lld ",phi[i]);
	
	while(T--) printf("%lld\n",dfs(Read()));
	
	return 0;
}
