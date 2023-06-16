/*
	ax + by = gcd(a,b) 
*/
# include <cstdio>

inline int Gcd(const int a,const int b){return b ? Gcd(b,a % b) : a;}

int main()
{
	register int n,x,gcd = 0;
	
	scanf("%d",&n);
	
	for(register int i = 1; i <= n ; ++i)
	{
		scanf("%d",&x);
		
		x < 0 ? x = -x : 0;
		
		gcd = Gcd(gcd,x);
	}
	
	printf("%d",gcd);
	
	return 0;
}
