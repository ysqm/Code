# include <cstdio>
# include <algorithm>
# include <bitset>
# include <cstring>
# define reg register
using namespace std;

inline void in(int& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}

int w[3042],v[3042],id[3042],n,sum[242],k,tot,dp[20042];//200 * 2 ^ 15 ==32000
bool from[3042][20042];

int main()
{
	memset(dp,0x7f,sizeof(dp));dp[0] = 0;
	
	in(n);tot = n;
	
	for(reg int i = 1; i <= n; ++i) in(w[i]);
	
	for(reg int i = 1,a; i <= n; ++i){
		in(a);
		for(reg int j = 0; a > (1 << j); ++j){
			v[++tot] = (1 << j);
			a -= v[tot];
			w[tot] = w[i] * v[tot];
			id[tot] = i;
		}
		v[i] = a;
		w[i] = w[i] * a;
		id[i] = i;
	}
	
	in(k);
	
	for(reg int i = 1; i <= tot; ++i)
		for(reg int j = k,a; j >= w[i]; --j){
			a = dp[j - w[i]] + v[i];
			if(dp[j] > a) {
				dp[j] = a;
				from[i][j] = 1;
			} 
		}
	
	printf("%d\n",dp[k]);
	
	for(reg int i = tot,m = dp[k]; m ;){
		while(!from[i][k]) i--;
		m -= v[i];sum[id[i]] += v[i]; k -= w[i--];
	}
	
	for(reg int i = 1; i <= n; ++i)
		printf("%d ",sum[i]);
	return 0;
}
