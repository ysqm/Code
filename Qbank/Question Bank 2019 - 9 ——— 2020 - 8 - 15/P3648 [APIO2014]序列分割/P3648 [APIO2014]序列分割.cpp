# include <cstdio>
# include <algorithm>
# define N 100000
# define LL long long
# define reg register

inline void in(LL& x)
{
	x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	//x *= f;
}

inline LL Read()
{
	LL x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}
	
LL Y[N + 42],dp[N + 42],n,k,s[N + 42],g[N + 42];
int q[N + 42],f[N + 42][202];

double srt(const int& i,const int& j)
{
	if(s[i] == s[j]) return -1e18;
	else return (double)(Y[j] - g[j] + g[i] - Y[i]) / (s[j] - s[i]);
}

int main()
{
	in(n);in(k);
	
	for(reg int i = 1; i <= n ; ++i){s[i] = s[i - 1] + Read();Y[i] = s[i] * s[i];}
	
	for(reg int ti = 1; ti <= k; ++ti){
		for(reg int j = 1; j <= n; ++j) g[j] = dp[j];
		
		reg int h = 0,t = 0;
		
		for(reg int i = 1; i <= n; ++i){
			while(h < t && srt(q[h],q[h + 1]) <= s[i]) ++h;
			
			if(h <= t){
				dp[i] = g[q[h]] + s[q[h]] * (s[i] - s[q[h]]);
				f[i][ti] = q[h];
			}
			else dp[i] = 0;
			
			while(h < t && srt(q[t],q[t - 1]) >= srt(i,q[t])) --t;
			
			q[++t] = i;
		}
		
	}
	
	printf("%lld\n",dp[n]);
	
	for(reg int i = f[n][k]; k ; i = f[i][--k]) printf("%d ",i);
	
	return 0;
}
