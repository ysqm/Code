/*
	ax + by = gcd(a,b)
	
	对于无解的情况下是  c % gcd(a,b) != 0; 
*/
# include <cstdio>
# include <cmath>

typedef long long LL;

inline LL Read()
{
	register LL x = 0;register char c = getchar();
	
	while(c < '0' || c > '9') c = getchar();
	
	while(c >= '0' && c <= '9') {x = x * 10 + (c ^ 48);c = getchar();}
	
	return x;
}

inline LL Gcd(const LL a,const LL b){return b ? Gcd(b,a % b) : a;}

inline LL Exgcd(const LL a,const LL b,LL& x,LL& y)
{
	if(b == 0) x = 1;
	
	else {
		Exgcd(b,a % b,y,x);
		
		y -= a / b * x;
	}
}

LL T,a,b,c,gcd,x,y,max_x,min_x,max_y,min_y;

int main()
{
	T = Read();
	
	for(register int i = 1; i <= T ; ++i)
	{
		a = Read();b = Read();c = Read();x = y = 0;
		
		if(c % (gcd = Gcd(a,b))) puts("-1");
		
		else{
			
			a /= gcd;b /= gcd;c /= gcd; 
			
			Exgcd(a,b,x,y);
			
			x *= c;y *= c;
			
			min_x = x > 0 && x % b != 0 ? x % b : x % b + b;
			
			min_y = y > 0 && y % a != 0 ? y % a : y % a + a;
			
			max_x = (c - min_y * b) / a;
			
			max_y = (c - min_x * a) / b;
			
			if(max_x > 0 && (max_x - min_x) / b + 1 != 0) printf("%lld %lld %lld %lld %lld\n",(max_x - min_x) / b + 1,min_x,min_y,max_x,max_y);
			
			else printf("%lld %lld\n",min_x,min_y);
			
			//printf("Case : %lld*%lld+%lld*%lld=%lld\nmin_x=%lld \nmin_y=%lld\n\n",a,x,b,y,c,min_x,min_y);
		}
	}
	
	return 0;
}
