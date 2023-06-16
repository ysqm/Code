# include <cstdio>

int n,ans = 2;
long long a[424242];

int main()
{
	scanf("%d",&n);
	
	if(n == 1){puts("0");return 0;}
	
	for(register int i = 1; i <= n ; ++i) a[i] = i;
	
	for(register int i = 2; i <= n ; ++i)
		if(a[i] == i)
			for(register int j = i; j <= n ; j += i)
				a[j] = a[j] / i * (i - 1);
	
	for(register int i = 2; i < n ; ++i) ans += (a[i] << 1);

	printf("%d\n",ans + 1);
	
	return 0;
}
