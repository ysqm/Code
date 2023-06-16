# include <cstdio>
# include <algorithm>
# define N 1000000
# define LL long long
# define reg register

inline void in(LL& x)
{
	x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	//x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}
	
LL dp[N + 42],n,s[N + 42],sp[N + 42],c[N + 42],x[N + 42];
int q[N + 42];

int main()
{
	in(n);
	
	for(reg int i = 1; i <= n ; ++i){
		in(x[i]);in(sp[i]);in(c[i]);
		s[i] = s[i - 1] + x[i] * sp[i];
		sp[i] += sp[i - 1];
	}
	
	reg int h = 0,t = 0;
	
	for(reg int i = 1; i <= n; ++i){
		while(h < t && (double)(dp[q[h]] - dp[q[h + 1]] + s[q[h]] - s[q[h + 1]]) / (sp[q[h]] - sp[q[h + 1]]) <= x[i]) ++h;
		dp[i] = dp[q[h]] + x[i] * (sp[i] - sp[q[h]]) - s[i] + s[q[h]] + c[i];
		while(h < t && (double)(dp[q[t]] - dp[q[t - 1]] + s[q[t]] - s[q[t - 1]]) / (sp[q[t]] - sp[q[t - 1]]) >= (double)(dp[i] - dp[q[t]] + s[i] - s[q[t]]) / (sp[i] - sp[q[t]])) --t;
		q[++t] = i;
	}
	printf("%lld",dp[n]);
	return 0;
}
