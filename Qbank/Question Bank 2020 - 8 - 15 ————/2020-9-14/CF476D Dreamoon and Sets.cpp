# include <cstdio>
# include <algorithm>
# define ll long long

int n,k,base = 1;

int main()
{
	scanf("%d %d",&n,&k);
	printf("%d\n",(base+(n-1)*6+4)*k);
	for(int i = 1; i <= n ; ++i)
	{
		printf("%d %d %d %d\n",base*k,(base+1)*k,(base+2)*k,(base+4)*k);
		base += 6;
	}
	return 0;
}
