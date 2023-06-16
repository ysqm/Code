# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
# define LL long long
# define int long long 
using namespace std;

int num[42];
LL l,r,m,f[42],t[42],cnt1[42],cnt2[42];
//1 99999999999999999 
void Pretreatment()
{
	t[1] = f[1] = 1;
	
	for(reg int i = 2; i <= 18 ; ++i) t[i] = t[i-1]*10;
	
	for(reg int i = 2; i <= 18 ; ++i) f[i] = f[i-1]*10+t[i];
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
				cnt[j] += f[i-1] * num[i];// 
			
			for(reg int j = 1; j < num[i] ; ++j) 
				cnt[j] += t[i];
			
			LL sum = 0;
			
			for(reg int j = 1; j < i ; ++j) sum += t[j]*num[j];
			
			cnt[num[i]] += sum + 1;
		}
	}
	
}

signed main()
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
	
		for(reg int i = 1 ; i <= 9 ; ++i) sum += (cnt2[i] - cnt1[i]) * i;
	
		printf("%lld\n",sum);
	}
	
	return 0;
} 

