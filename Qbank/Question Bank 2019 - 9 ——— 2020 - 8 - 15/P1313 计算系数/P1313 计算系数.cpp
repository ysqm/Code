# include <cstdio>
# include <algorithm>
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

int a,b,k,n,m;
long long f[1005][1005];

int main()
{
	in(a);in(b);in(k);in(n);in(m);
	
	f[0][0] = 1;
	
	for(reg int j = 1; j <= m ; ++j) f[0][j] = (f[0][j] + f[0][j - 1] * b) % 10007;
	
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = 0; j <= m ; ++j){
			
            f[i][j] = (f[i][j] + f[i - 1][j] * a) % 10007;
            
            if (j > 0)
                    f[i][j] = (f[i][j] + f[i][j - 1] * b) % 10007;
			
		}
	
	printf("%lld\n",f[n][m]);
	
	return 0;
}

