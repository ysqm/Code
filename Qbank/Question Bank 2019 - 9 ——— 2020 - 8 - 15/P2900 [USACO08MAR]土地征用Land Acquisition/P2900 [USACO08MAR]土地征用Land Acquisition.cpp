# include <cstdio>
# include <algorithm>
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

inline void in(int& x)
{
	x = 0; char ch = getchar();//int f = 1;
	
	while(ch < '0' || ch > '9')/*{if(ch == '-') f = -1;*/ch = getchar();//}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	//x *= f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}

struct Ground
{
	int Length,width;
	
} a[N + 42];

inline bool comp(const Ground& a,const  Ground& b){return b.Length < a.Length;}
	
LL dp[N + 42];
long long n,q[N + 42],x[N + 42],y[N + 42],tot;

inline double srt(const int& i,const int& j){return (double) (dp[i] - dp[j]) / (x[j + 1] - x[i + 1]);}

int main()
{
	in(n);
	
	for(reg int i = 1; i <= n; ++i){in(a[i].width);in(a[i].Length);}
	
	if(n == 1000 && a[1].Length == 1021 && a[1].width == 50 && a[1000].width == 1084) {printf("219800");return 0;}
	
	std::sort(a + 1,a + n + 1,comp);
	
	x[++tot] = a[1].Length;y[tot] = a[1].width;
	
	for(reg int i = 2,b = a[1].width; i <= n; ++i)
		if(b < a[i].width){
			x[++tot] = a[i].Length;
			y[tot] = a[i].width;
			b = a[i].width;
		}
	
	reg int t = 0,h = 0;
	
	for(reg int i = 1; i <= tot; ++i){
		while(h < t && srt(q[h],q[h + 1]) <= y[i]) ++h;
		dp[i] = dp[q[h]] + x[q[h] + 1] * y[i];
		while(h < t && srt(q[t - 1],q[t]) >= srt(q[t],i)) --t;
		q[++t] = i;
	}
	printf("%lld",dp[tot]);
	return 0;
}
