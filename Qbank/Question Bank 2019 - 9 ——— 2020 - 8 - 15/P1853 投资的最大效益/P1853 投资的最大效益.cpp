# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
# define N 100000000
# define LL long long
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}

int s,n,d,v[15],w[15],dp[N + 42];

int main()
{
	in(s);in(n);in(d);
	for(reg int i = 1; i <= d; ++i){in(w[i]);in(v[i]);}
	for(reg int year = 1; year <= n ; ++year){
		for(reg int i = 1; i <= d ; ++i)
			for(reg int j = w[i]; j <= s; j ++)
				dp[j] = Max(dp[j],dp[j - w[i]] + v[i]);
		s += dp[s];
	}
		
	printf("%d",s);
	return 0;
}
