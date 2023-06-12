# include <cstdio>
# include <queue>
# include <cstring>
# include <algorithm>
# define reg register 
# define LL long long

inline LL Read()
{
	LL x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

const LL p = 1e9+7,inv=570000004;

inline LL Pow(LL x,LL p1=p-2)
{
	LL res = 1;
	
	for( ; p1 ; p1>>=1,x = (x*x)%p)
		if(p1&1) res = (res*x)%p;
		
	return res;
}

int main()
{
	reg LL n,a1,a2,b1,b2,ine;
	
	n  = Read();
	
	a1 = 1;b1 = 0;
	
	while(n--)
	{
		a2 = Read()*inv%p;b2 = Read()*inv%p;
		
		ine = Pow((1-b1*b2%p+p)%p);
		
		a1 = a1*a2%p*ine%p;
		b1 = (b2+a2*a2%p*b1%p*ine%p)%p;
	}
	
	printf("%lld\n",a1);
	
	return 0;
}
