# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# define N 1000000
# define INF 0x7f7f7f7f
# define reg register
# define int long long

inline void in(int& x)
{
	x = 0; char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}
}

inline int Read()
{
	reg int x = 0;reg char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48);ch = getchar();}

	return x;
}

inline int Change_Signed(const int x){return x < 0 ? -x : x;}

int n,a[N + 42],AVE,K[N + 42],ans;

signed main()
{
	in(n);
	
	for(reg int i = 1; i <= n ; ++i) AVE += (a[i] = Read());
	
	AVE /= n;
	
	for(reg int i = 1; i <= n ; ++i) a[i] -= AVE;
	
	for(reg int i = 1; i <= n ; ++i) K[i] = K[i - 1] + a[i];
    
    std::sort(K + 1,K + n + 1);
    
    AVE = K[(n + 1) >> 1];
    
    for(reg int i = 1; i <= n ; ++i) ans += Change_Signed(AVE - K[i]);
        
   	printf("%lld\n",ans);
	
	return 0;
}
