# include <cstdio>
# define reg register

long long n,a[10042],len = 1;
long long b[10042] = {0,1};

int main()
{
	scanf("%lld",&n);
	
	reg long long tot = 0,d = 2,sum = 0;
	
	while(sum < n){
		
		sum += d;
		
		a[++tot] = d++;
	}
	
	a[sum - n - 1] = 0;
	
	for(reg long long i = 1; i <= tot ; ++i) if(a[i]) printf("%lld ",a[i]);
	
	for(reg long long i = 1; i <= tot ; ++i)
		if(a[i]){
			for(reg long long j = 1 ; j <= len ; ++j) b[j] *= a[i];
		
			for(reg long long j = 1 ; j <= len ; ++j) if(b[j] >= 10){b[j + 1] += b[j] / 10; b[j] %= 10;len = len > j + 1 ? len : j + 1;}
		
		}
	
	printf("\n");
	
	for(reg int i = len; i ; --i) printf("%lld",b[i]);
	
	return 0;
}
