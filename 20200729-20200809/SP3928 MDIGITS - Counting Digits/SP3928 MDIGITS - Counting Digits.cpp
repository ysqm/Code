# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
# define LL long long 
# define int long long
using namespace std;

int num[15];
LL n,m,T,f[15],t[15],cnt1[15],cnt2[15];

void Pretreatment()
{
	t[1] = f[1] = 1;
	
	for(reg int i = 2; i <= 13 ; ++i) t[i] = t[i-1]*10;
	
	for(reg int i = 2; i <= 13 ; ++i) f[i] = f[i-1]*10+t[i];
}

void Query(LL x,LL cnt[])
{
	if(x > 0)
	{
		int len = 0;
	
		while(x)
		{
			num[++len] = x%10;
			x /= 10;
		}
	
		for(reg int i = len ; i ; --i)
		{
			for(reg int j = 0; j <= 9 ; ++j) 
				cnt[j] += f[i-1] * num[i];// 
			
			for(reg int j = 0; j < num[i] ; ++j) 
				cnt[j] += t[i];
			
			LL sum = 0;
			
			for(reg int j = 1; j < i ; ++j) sum = sum + t[j]*num[j];
			
			cnt[num[i]] += sum + 1;
			
			cnt[0] -= t[i];
		}
	}
	
}

signed main()
{
	Pretreatment();
	
	while(scanf("%lld%lld",&n,&m) && (m || n))
	{
		if(n > m) n ^= m ^= n ^= m;
		
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		
		Query(n-1,cnt1);
	
		Query(m,cnt2);
	
		for(reg int i = 0 ; i < 9 ; ++i) printf("%lld ",cnt2[i]-cnt1[i]);
		
		printf("%lld\n",cnt2[9]-cnt1[9]);
	}
	
	return 0;
} 

