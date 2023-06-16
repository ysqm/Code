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

long long n,T,a,b,c,m;

int main()
{
	T = Read();
	
	while(T--)
	{
		a = Read();b = Read();c = Read();n = Read();
		
		m = max(a,max(b,c));
		
		n = n - (m*3-a-b-c);

		if(n < 0||n%3) puts("NO");
		else puts("YES");
	}
	
	return 0;
} 
