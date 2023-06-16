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
	else return (double)(g[i] + s[i] * s[i] - g[j] - s[j] * s[j]) / (s[i] - s[j]);
}

int main()
{
	in(n);in(k);
	
	for(reg int i = 1; i <= n ; ++i){s[i] = s[i - 1] + Read();g[i] = s[i] * s[i];}
	
	for(reg int ti = 1; ti < k; ++ti){
		reg int h = 1,t = 1;q[1] = ti;
		
		for(reg int i = ti + 1; i <= n; ++i){
			while(h < t && srt(q[h],q[h + 1]) <= 2 * s[i]) ++h;
			
			dp[i] = g[q[h]] + (s[i] - s[q[h]]) * (s[i] - s[q[h]]);
			
			while(h < t && srt(q[t],q[t - 1]) >= srt(q[t],i)) --t;
			
			q[++t] = i;
		}
		
		for(reg int j = 1; j <= n; ++j) g[j] = dp[j];
	}
	
	printf("%lld\n",k * dp[n] - s[n] * s[n]);
	
	return 0;
}
