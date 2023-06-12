# include <cstdio>
# include <algorithm>
using namespace std;

const int t[] = {0,1,10,100,1000,10000,100000,1000000,10000000,1000000000};

int n,a,ans[42],s[12];

int main()
{
	scanf("%d",&n);
	
	int len = 0;
	
	while(n)
	{
		s[++len] = n % 10;
		
		a = max(a,s[len]);
		
		n /= 10;
	}
	
	printf("%d\n",a);
	
	for(int i = 1; i <= len ; ++i)
	{
		int j = 0;
		
		while(s[i])
		{
			ans[++j] += t[i];
			--s[i];
		}
	}
	
	for(int i = 1; i <= a ; ++i) printf("%d ",ans[i]);
	
	return 0;
} 
