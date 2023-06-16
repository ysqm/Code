# include <cstdio>
# include <algorithm>
# define ll long long

inline ll qpow(ll x,int p,const int mod)
{
	ll res = 1;
	for(; p ; p>>=1,x = x*x%mod) 
		if(p&1) res=res*x%mod;
	return res;
}

bool check(const int x)
{
	for(int i = 2; i*i <= x ; ++i) if(x%i==0) return false;
	return true;
}

int n;

int main()
{
	scanf("%d",&n);
	if(n == 4) printf("YES\n1\n3\n2\n4");
	else if(!check(n)) puts("NO");
	else 
	{
		printf("YES\n1\n");
		for(int i = 2; i < n ; ++i) printf("%lld\n",i*qpow(i-1,n-2,n)%n);
		if(n > 1) printf("%d\n",n);
	}
	return 0;
}
