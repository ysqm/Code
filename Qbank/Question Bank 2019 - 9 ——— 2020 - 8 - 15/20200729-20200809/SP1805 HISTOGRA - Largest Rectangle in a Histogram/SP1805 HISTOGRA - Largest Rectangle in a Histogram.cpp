# include <algorithm>
# include <cstring>
# include <cstdio>
# include <cmath>
# define reg register
# define int long long
# define N 100000
using namespace std;

typedef long long LL;

inline int Read()
{
    int x = 0;char ch = getchar();

    while(ch < '0' || ch > '9') ch = getchar();

    while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}

    return x;
}

int n,T,S[N + 42];
LL h[N + 42],w[N + 42];
//7 2 1 4 5 1 3 3
signed main()
{
	while(n = Read())
	{
		for(reg int i = 1; i <= n ; ++i) h[i] = Read();
		
		h[++n] = 0;
		
		reg LL ans = 0;
		reg int top = 0;
		
		for(reg int i = 1; i <= n ; ++i)
		{
			if(h[i] <= S[top])
			{
				reg int len = 0;
				
				while(h[i] < S[top])
				{
					len += w[top];
					
					if(ans < len * S[top]) ans = len * S[top];
					
					top--;
				}
				
				S[++top] = h[i];
				w[top] = len+1;
			}
			
			else
			{
				S[++top] = h[i];
				w[top] = 1;
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
} 

