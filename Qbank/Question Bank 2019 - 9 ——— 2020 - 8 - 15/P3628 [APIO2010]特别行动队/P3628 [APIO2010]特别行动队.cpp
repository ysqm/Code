# include <cstdio>
# include <algorithm>
# define N 1000000
# define LL long long
# define reg register

inline void in(LL& x)
{
	x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	x *= f;
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
	
LL dp[N + 42];
LL n,a,b,c,s[N + 42],K[N + 42],Y[N + 42],B[N + 42];
int q[N + 42];

int main()
{
	in(n);in(a);in(b);in(c);
	
	for(reg int i = 1; i <= n; ++i){
		s[i] += s[i - 1] + Read();
		B[i] = a * s[i] * s[i] + b * s[i] + c;
		K[i] = 2* s[i] * a;
		Y[i] = a * s[i] * s[i] - b * s[i];
	}
	
	reg int h = 0,t = 0;
	
	for(reg int i = 1; i <= n; ++i){
		while(h < t && (dp[q[h]] + Y[q[h]] - dp[q[h + 1]] - Y[q[h + 1]]) / (double)(s[q[h]] - s[q[h + 1]]) >= K[i]) ++h;
		dp[i] = B[i] + dp[q[h]] + Y[q[h]] - K[i] * s[q[h]];
		while(h < t && (dp[q[t - 1]] + Y[q[t - 1]] - dp[q[t]] - Y[q[t]]) / (double)(s[q[t - 1]] - s[q[t]]) <= (dp[q[t]] + Y[q[t]] - dp[i] - Y[i]) / (s[q[t]] - s[i])) --t;
		q[++t] = i;
	}
	printf("%lld",dp[n]);
	return 0;
}
