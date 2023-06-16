# include <cstdio>
# include <cstring>
# define reg register
# define LL long long

const int p[] = {3,5,7,9,11,13,17,19,23,29};

int tot; 
LL prime[10000005];
bool vis[1000005];

inline LL Mod(const LL x,const int mod){return x - (x/mod)*mod;}

inline LL qpow(reg LL x,reg int p,reg int mod)
{
	LL res = 1; 

	for(; p ; p>>=1,x = Mod(x*x,mod)) if(p&1) res = Mod(x*res,mod);

	return res;
}

inline bool Miller_Rabin(const LL x)
{
	if(x == 2) return true;
	else if(x <= 1 || (x&1)^1) return false;
	if(x < 30)
	{
		for(reg int i = 0; i <= 9 ; ++i) if (*(p+i) == x) return true;
		
		return false;
	}
	reg int i,j,k,s=0,t=x-1;

	while(!(t&1)){++s;t>>=1;}

	for(i = 0; i <= 9 ; ++i)
	{
		LL b = qpow(*(p+i),t,x);
		for(j = 1; j <= s ; ++j)
		{
			k = Mod(b*(LL)b,x);
			if((k==1) && (b!=1) && (b!=(x-1))) return false;
			b=k;
		}
		if(b!=1) return false;
	}

	return true;
}

int main()
{
	reg LL L,R;

	//scanf("%d",&L);

	/*while(L--)
	{
		scanf("%d",&R);
		if(Miller_Rabin(R)) puts("yes,maybe is a Prime.");
		else puts("Isn't a prime.");
	}*/

	while(~scanf("%lld%lld",&L,&R))
	{
		memset(vis,0,sizeof(vis));
		
		for(reg LL i = L ;i <= R; i++)
    	if(!vis[i-L])
		{
			if(Miller_Rabin(i))
            {
                LL l = i + i;
                while(l<=R)
                {
                    vis[l-L] = true;
                    l += i;
                }
        	}
        	else vis[i-L] = true;
    	}tot = 0;
		
		for(reg int i = 0; i <= R-L ; ++i) if(!vis[i]) prime[++tot] = i;
		
		if(tot <= 1) puts("There are no adjacent primes.");
		else
		{
			int num1=0,num2=0,min=1e9,max=0;

			for(reg int i = 2; i <= tot ; ++i)
			{
				if(prime[i]-prime[i-1] > max){max = prime[i]-prime[i-1];num2 = i;}
				if(prime[i]-prime[i-1] < min){min = prime[i]-prime[i-1];num1 = i;}
			}

			printf("%lld,%lld are closest, %lld,%lld are most distant.\n",prime[num1-1]+L,prime[num1]+L,prime[num2-1]+L,prime[num2]+L);
		}
	}

	return 0;
}
