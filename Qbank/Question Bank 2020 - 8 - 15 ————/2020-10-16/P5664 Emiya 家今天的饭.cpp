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
# define N 200
# define M 3000
# define LL long long
# define reg register
# define mod 998244353
# define Gc getchar()
//# define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1<<15],*SS=BB,*TT=BB;
inline LL Read()
{
    register LL x = 0;char ch = Gc;
	
    while(ch < '0' || ch > '9') ch = Gc;
	
    while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}
	
    return x;
}

int n,m;
LL a[N+5][M+5],f[N+5][M*2+5],ans = 1,cnt[N+5],MainDish[N+5],Dish[N+5];

inline void INIT()
{
	scanf("%d%d",&n,&m);
    for(int i = 1; i <= n ; ++i)
    {
        for(int j = 1; j <= m ; ++j)
        {
            a[i][j] = Read();
            cnt[i] = ((cnt[i]+a[i][j]))%mod;
        }
        ans = ans * (cnt[i]+1)%mod;
    }
    ans = (ans+mod-1)%mod;
    for(int i = 1; i <= m ; ++i)
    {
        f[0][100] = 1;
        for(int j = 1; j <= n ; ++j) Dish[j] = cnt[j]-a[j][i];
        for(int j = 1; j <= n ; ++j) MainDish[j] = a[j][i];
        for(int j = 1; j <= n ; ++j) if(Dish[j] < 0) Dish[j] += mod;
        for(int j = 1; j <= n ; ++j)
            for(int k = ~j+1; k <= j ; ++k)
                {
                    f[j][k+100] = (f[j-1][k+100]+f[j-1][k+101]*Dish[j]%mod)%mod;
                    if(k+99 >= 0) f[j][k+100] = (f[j][k+100] + f[j-1][k+99]*MainDish[j]%mod)%mod;
                }
        for(int i = 1; i <= n ; ++i) ans = (ans+mod-f[n][i+100])%mod;
    }
    printf("%lld",ans);
}

signed main()
{
	INIT();
	return 0;	
}
