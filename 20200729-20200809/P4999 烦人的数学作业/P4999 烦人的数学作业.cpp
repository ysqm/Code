# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
# define LL long long
using namespace std;

const LL mod = (1e9) + 7;

int num[42];
LL l,r,m,f[42],t[42],cnt1[42],cnt2[42];
//1 99999999999999999 
void Pretreatment()
{
	t[1] = f[1] = 1;
	
	for(reg int i = 2; i <= 20 ; ++i) t[i] = (t[i-1]*10) % mod;
	
	for(reg int i = 2; i <= 20 ; ++i) f[i] = (f[i-1]*10+t[i]) % mod;
}

void Query(LL x,LL *cnt)
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
			for(reg int j = 1; j <= 9 ; ++j) 
				cnt[j] = (cnt[j] + f[i-1] * num[i]) % mod;// 
			
			for(reg int j = 1; j < num[i] ; ++j) 
				cnt[j] = (t[i]+cnt[j]) % mod;
			
			LL sum = 0;
			
			for(reg int j = 1; j < i ; ++j) sum = sum + t[j]*num[j];
			
			cnt[num[i]] = (cnt[num[i]] + sum + 1) % mod;
		}
	}
	
}

int main()
{
	scanf("%lld",&m);
	
	Pretreatment();
	
	while(m--)
	{
		scanf("%lld%lld",&l,&r);
		
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		
		Query(l-1,cnt1);
		
		Query(r,cnt2);
	
		LL sum = 0; 
	
		for(reg int i = 1 ; i <= 9 ; ++i) sum = ((cnt2[i] - cnt1[i]) * i + sum + mod) % mod;
	
		printf("%lld\n",(sum + mod) % mod);
	}
	
	return 0;
} 

