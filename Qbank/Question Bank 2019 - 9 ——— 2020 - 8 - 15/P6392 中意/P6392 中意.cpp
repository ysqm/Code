/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
=======`-.____`-.___\_____/___.-`____.-'=======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  	 Buddha said:
         	 	 The program have no BUG.
         	 	 The program can pass the text.	 	 
*/
# include <cstdio>
# include <cstring>
# define N 100
# define M 2000
# define LL long long
# define reg register
# define mod 998244353
# define int long long

inline int Read()
{
	int x = 0;char ch = getchar();
	
	while(ch < '0' || ch > '9') ch = getchar();
	
	while(ch <= '9' && ch >= '0'){x = x*10 + (ch^48);ch = getchar();}
	
	return x;
}

int n,m,a[N + 42][M + 42];
LL s[N + 42][M + 42],f[N + 42][(N << 1) + 42],g[N + 42][N + 42];

inline void INIT()
{
	n = Read();m = Read();
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
			s[i][0] = ((a[i][j] = Read()) + s[i][0]) % mod;
	
	for(reg int i = 1; i <= n ; ++i)
		for(reg int j = 1; j <= m ; ++j)
			s[i][j] = (s[i][0] - a[i][j] + mod) % mod;
	
	for(reg int i = 0; i <= n; ++i) g[i][0] = 1;
	
	for(reg int i = 1; i <= n; ++i)
		for(reg int j = 1; j <= n ; ++j)
			g[i][j] = g[i-1][j] + g[i-1][j-1] * s[i][0] % mod;
}

inline void DP()
{
	LL ans = 0;
	
	for(reg int k = 1; k <= m; ++k)
    {
        memset(f,0,sizeof(f));
        
        f[0][n] = 1;
        
        for(reg int i = 1; i <= n; ++i)
        	for(reg int j = n-i; j <= n+i ; ++j) 
                f[i][j] = (f[i-1][j] + f[i-1][j-1] * a[i][k] % mod + f[i-1][j+1] * s[i][k] % mod) % mod;
        
        for(reg int j = 1; j <= n; ++j) ans = (ans + f[n][n+j]) % mod;
	}
	
	for(reg int j = 1; j <= n; ++j) ans = (ans - g[n][j] + mod)%mod;
	
	printf("%lld\n",((-ans) % mod + mod)% mod);

}

signed main()
{
	INIT();
	
	DP();

	return 0;	
}
