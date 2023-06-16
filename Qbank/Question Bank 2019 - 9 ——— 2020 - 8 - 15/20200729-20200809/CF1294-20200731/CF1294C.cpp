# include <algorithm>
# include <cstdio>
# include <cmath>
# define reg register
# define N 50000
# define Ls(i) (i<<1)
# define Rs(i) (i<<1|1)
using namespace std;

inline int Read()
{
    int x = 0,f=1;char ch = getchar();

    while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}

    while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}

    return x*f;
}

int n,T,m;

inline int Spit(int x,int y)
{
	int m = sqrt(x);
	
	for(reg int i = y + 1; i <= m ; ++i)
		if(x%i == 0) return i;
	return -1;
}

int main()
{
	T = Read();
	
	while(T--)
	{
		reg int a,b;
		
		n = Read();
		
		a = Spit(n,1);
		
		if(a == -1) puts("NO");
		
		else
		{
			n /= a;
		
			b = Spit(n,a);
		
			if(b == -1) puts("NO");
			
			else
			{
				n /= b;
			
				if(n == b) puts("NO");
			
				else printf("YES\n%d %d %d\n",a,b,n);
			}
			
		}
	}
	
	return 0;
} 
