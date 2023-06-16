# include <cstdio>
# include <algorithm>
# define N 300000
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
	int x = 0; char ch = getchar();int f = 1;
	
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x * f;
}

inline int Max(const int& a,const int b){return a > b ? a : b;}
inline int Min(const int& a,const int b){return a < b ? a : b;}

LL n,s,ti[N + 42],c[N + 42],q[N + 42],dp[N + 42];

inline int sf(int L,int R,const LL S)
{
	int mid,res;
	
	while(L <= R){
		mid = (L + R) >> 1;
		if(dp[q[mid + 1]] - dp[q[mid]] > S * (c[q[mid + 1]] - c[q[mid]])){R = mid - 1;res = mid;}
		else L = mid + 1;
	}
	
	return q[res];
}

int main()
{
	in(n);in(s);
	
	for(reg int i = 1; i <= n; ++i){ti[i] = ti[i - 1] + Read();c[i] = c[i - 1] + Read();dp[i] = 0x7f7f7f;}
	
	reg int h = 1,t = 1;
	
	for(reg int i = 1; i <= n; ++i){
		int p = sf(h,t,s + ti[i]);
		dp[i] = dp[p] + ti[i] * c[i] + s * c[n] - c[p] * (s + ti[i]);
		while(h < t && (dp[i] - dp[q[t]]) * (c[q[t]] - c[q[t - 1]]) <= (dp[q[t]] - dp[q[t - 1]]) * (c[i] - c[q[t]])) --t;
		q[++t] = i;
 	}
 	
  	printf("%lld",dp[n]);
 	
 	return 0;
}
