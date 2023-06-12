# include <cstdio>
# include <vector>
# include <queue>
# define reg //register
# define INF 0x7f7f7f7f7f7f7f7f
# define Gc getchar()//*/(SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;

typedef long long LL;

inline int Read()
{
	register int x = 0,f=1;register char ch = Gc;
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = Gc;}
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return f < 0 ? (~x+1) : x;
}

inline LL ReadL()
{
	register LL x = 0;register int f=1;register char ch = Gc;
	
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = Gc;}
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = Gc;}
	
	return f < 0 ? (~x+1) : x;
}

inline LL Min(const LL a,const LL b){return a < b ? a : b;}
inline LL Max(const LL a,const LL b){return a > b ? a : b;}

int n,w,s,q[5505];
LL dp[5505],g[5505],ans = -INF,a[5505];

int main()
{
	#ifdef ONLINE_JUDGE
	#else
    freopen("4.txt","r",stdin);
	#endif
	
	n = Read();w = Read();s = Read();
	
	for(reg int i = 1; i <= n ; ++i) a[i] = Read();
	
	for(reg int i = 1; i <= n ; ++i)
	{
		for(reg int j = 0; j <= n ; ++j) dp[j] = -INF;
		
		q[1] = Min(w,i-1);
		
		for(reg int j = Min(w,i),h=1,t=1; j >= 1; --j)//到现在的状态，锅内放了几种 
		{//因为是抛弃，所以只能由比它多的转移过来 
			while(h <= t && q[h] > j + s - 1) ++h;
			while(h <= t && g[q[t]] <= g[j-1]) --t;
			q[++t] = j-1;
			dp[j] = g[q[h]] + j*a[i];
		}
		
		for(reg int j = 0; j <= n ; ++j) g[j] = dp[j];
	}
	
	for(reg int i = 0; i <= w; ++i) ans = Max(ans,g[i]);
	
	printf("%lld",ans);
	
	return 0;
}


