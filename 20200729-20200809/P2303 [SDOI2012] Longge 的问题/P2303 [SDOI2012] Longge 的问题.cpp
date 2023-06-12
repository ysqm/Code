# include <cstdio>
# include <algorithm>
# define reg register
# define N 10000000 

typedef long long LL;

LL n;

/*inline LL F()
{
	long long ans = n,i;
	
	for(reg int i = 2; i * i <= n ; ++i)
		if(n%i==0)
		{
			int sump = 0;
			
			while(n%i==0){n/=i;++sump;}
			
			
			
		}
	
	return ans;
}*/

inline LL phi(LL x)
{
	LL res = x;
	
	for(reg int i = 2; i*i <= x ; ++i)
	{
		if(x%i==0) res = res/i * (i-1);
		while(x%i == 0) x /= i;
	}
	
	if(x > 1) res = res/x * (x-1);
	
    return res;
} 

inline LL F()
{
	LL res = 0;
	
	reg int i = 1;
	
    for(i = 1; (LL)i*i < n; ++i)
        if(n % i == 0) res += i * phi(n/i) + (n/i) * phi(i);
        
    if((LL)i * i == n) res += i * phi(i);
    
    return res;
}

int main()
{
	scanf("%lld",&n);
	
	printf("%lld",F());
	
	return 0;
}



