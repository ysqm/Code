# include <ctime>
# include <cmath>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# define N 150
//# define M 2000
# define M 20000000
# define reg register
# define LL long long
# define FileRead(x) freopen(#x".in","r",stdin)
# define FileWrite(x) freopen(#x".out","w",stdout)
namespace IO
{
    # define Gc (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
    char BB[1<<15],*SS=BB,*TT=BB;
    inline int Read()
    {
        register int x = 0;char ch = Gc;

        while(ch < '0' || ch > '9')ch = Gc;

        while(ch >= '0' && ch <= '9'){x = x*10+(ch^48);ch = Gc;}

        return x;
    }

    inline int Max(const int x,const int y){return x < y ? y : x;}
    inline int Min(const int x,const int y){return x < y ? x : y;}
}

namespace Solution
{
    const LL mod = 1000000007;
    const int Max_Status = (1<<16)-1;
    int c[17][17],n,Status;
    LL g[Max_Status],f[Max_Status];
    inline LL Mod(const LL x){return x >= mod ? x-mod : x;}
    int Solve()
    {
    	FileRead(ysqm);
    	n = IO::Read();
        for(int i = 1; i <= n ; ++i)
            for(int j = 1; j <= n ; ++j)
                c[i][j] = IO::Read();
        Status = (1<<n)-1;
        for(int i = 0; i <= Status ; ++i) f[i] = 1;
        for(int S = 0; S <= Status ; ++S)
        	for(int i = 1; i <= n ; ++i)
        		if(S&(1<<(i-1)))
        			for(int j = i+1; j <= n ; ++j)
        				if(S&(1<<(j-1)))
        					f[S] = f[S]*(c[i][j]+1)%mod;
        for(int S = 1; S <= Status ; ++S)
        {
        	g[S] = f[S];
        	int A = S^(S&(-S));
        	for(int G = A; G ; G = (G-1)&A) g[S] = (g[S]-f[G]*g[G^S]+mod)%mod;
		}
        printf("%lld\n",g[Status]);
        return 0;
    }
}

int main(){return Solution::Solve();}
