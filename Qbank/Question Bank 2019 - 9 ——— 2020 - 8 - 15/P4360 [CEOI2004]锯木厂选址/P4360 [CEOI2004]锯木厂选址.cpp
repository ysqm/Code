# include <cstdio>
# include <algorithm>
# define N 20000
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
	
LL dp[N + 42],n,d[N + 42],w[N + 42],s[N + 42],x[N + 42],ans = 0x7f7f7f7f7f,tot;
int q[N + 42];

inline double srt(const int& i,const int& j){return (double)(d[i] * s[i] - d[j] * s[j]) / (s[i] - s[j]);}

int main()
{
	in(n);
	
	for(reg int i = 1; i <= n ; ++i){in(w[i]);in(d[i]);s[i] = s[i - 1] + w[i];}
	
	for(reg int i = n; i > 0; --i) d[i] += d[i + 1];
	
	for(reg int i = 1; i <= n; ++i) tot += d[i] * w[i];
	
	reg int h = 0,t = 0;
	
	for(reg int i = 1; i <= n; ++i){
		while(h < t && srt(q[h],q[h + 1]) >= d[i]) ++h;
		ans = Min(ans,tot - d[q[h]] * s[q[h]] - d[i] * (s[i] - s[q[h]]));
		while(h < t && srt(q[t - 1],q[t]) <= srt(q[t],i)) --t;
		q[++t] = i;
	}
	printf("%lld",ans);
	return 0;
}
