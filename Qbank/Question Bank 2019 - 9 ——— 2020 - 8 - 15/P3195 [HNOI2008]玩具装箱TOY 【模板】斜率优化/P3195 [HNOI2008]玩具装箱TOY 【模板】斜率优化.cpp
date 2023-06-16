# include <cstdio>
# define N 50000
# define LL long long
# define reg register


inline void in(LL& x)
{
	x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	//x *= f;
}

inline int Read()
{
	int x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')ch = getchar();//{if(ch == '-') f = -1;}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}

LL dp[N + 42],g[N + 42];
LL n,L,C[N + 42],q[N + 42],f[N + 42];

inline double srt(int i,int j){return (double) (dp[j] + g[j] - dp[i] - g[i]) / (f[j] - f[i]);}

int main()
{
	in(n);in(L);++L;//L = L + 1,省略了 L 
	//dp[i] = min{dp[j] + (s[i] - s[j] + i - j - L)^2} j < i 
	for(reg int i = 1; i <= n; ++i) {
		C[i] = C[i - 1] + Read();
		f[i] = C[i] + i;//换元 
		g[i] = (f[i] + L) * (f[i] + L);//换元 
	}
	
	reg int h = 0,t = 0;/*重点*/g[0] = L * L;//g[0]是(f[0]+L)*(f[0]+L) f[0] = 0 所以 g[0]=L*L 
	
	for(reg int i = 1; i <= n; ++i){
		while(h < t && srt(q[h],q[h + 1]) <= (f[i] << 1)) h++;
		
		dp[i] = dp[q[h]] + (f[i] - f[q[h]] - L) *  (f[i] - f[q[h]] - L);
		
		while(h < t && srt(q[t],i) < srt(q[t - 1],q[t])) --t;//不要谈精度，除就是了，乘直接爆 0 
		
		q[++t] = i;
	}
	
	printf("%lld",dp[n]);
	return 0;
}
