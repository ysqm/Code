# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg //register
# define LL long long
using namespace std;

int num[42];
LL n,m,f[42],t[42],cnt2[42];

void Pretreatment()
{
	t[1] = f[1] = 1;
	
	for(reg int i = 2; i <= 13 ; ++i) t[i] = t[i-1]*10;
	
	for(reg int i = 2; i <= 13 ; ++i) f[i] = f[i-1]*10+t[i];
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

int main()
{
	scanf("%lld",&m);
	
	Pretreatment();
	
	Query(m,cnt2);
	
	LL sum = 0; 
	
	for(reg int i = 1 ; i <= 9 ; ++i) sum += cnt2[i] * i;
	
	printf("%lld",sum);
	
	return 0;
} 
