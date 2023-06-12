# include <cstdio> 

inline int Gcd(int a,int b)
{
	while(b ^= a ^= b ^= a %= b);
	
	return a;
}

int a,b,c;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	
	if(a > b) a ^= b ^= a ^= b;
	if(b > c) b ^= c ^= b ^= c;
	if(a > b) a ^= c ^= a ^= c;
	
	int d = Gcd(c,a);
	
	printf("%d/%d\n",a/d,c/d);
	
	return 0;
}
